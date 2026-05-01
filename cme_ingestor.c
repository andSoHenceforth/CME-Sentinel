#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile int state = 1;

void handle_signal_interrupt(int signal) {
	printf("\n[!] Halting ingestor (Signal %d)...\n", signal);
	state = 0;
}

int main() {
	signal(SIGINT, handle_signal_interrupt);
	printf("[+] CME Ingestor Started. Halt with Ctrl + C\n");
	while (state) {
		printf("[-] Checking API for new data of CME...\n");
		sleep(5);
	}

	printf("[+] Shutdown complete.");
	return 0;
	
}
