#include "Includes.h"
int main()
{
	SetWindowText(GetForegroundWindow(), random_string(15).c_str());
	printf(crypt("waiting fo cs:go! \n"));
	while (!mem.attach(crypt("csgo.exe"), PROCESS_ALL_ACCESS)){}
	std::this_thread::sleep_for(std::chrono::seconds(2));

	client_dll = mem.get_module(crypt("client.dll"));

	printf(crypt("attached succesfully! \nclient.dll base addr: 0x%X \nclient.dll size %d\n\n"), client_dll.dw_base, client_dll.dw_size);

	printf(crypt("initializing... \n\n"));

	std::this_thread::sleep_for(std::chrono::seconds(3));

	while (1)
	{
		DWORD local = mem.read<DWORD>(client_dll.dw_base + dwLocalPlayer);
		int health = mem.read<int>(local + m_iHealth);
		int team = mem.read<int>(local + m_iTeamNum);

		printf(crypt("Local base: 0x%X\n"), local);
		printf(crypt("Local health: %d\n\n"), health);
		printf(crypt("Local team: %d\n"), team);

		system("pause > nul");
		std::this_thread::sleep_for(std::chrono::milliseconds(15));
	}
}

