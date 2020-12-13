#include<iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <algorithm>
int main(int argc, char** argv) {
	int numbers[5];
	int median = 0;

	if (argc != 6) {
		std::cout << "Please enter 5 integers" << std::endl;
		return -1;
	}

	int pipeEnds1[2];
	int pipeEnds2[2];
	int pipeEnds3[2];
	int pipeEnds4[2];

	pid_t firstChild, secondChild;

	pipe(pipeEnds1);
	pipe(pipeEnds2);
	pipe(pipeEnds3);
	pipe(pipeEnds4);

	firstChild = fork();
	secondChild = fork();

	if (firstChild != 0) {
		for (int i = 0; i < 5; i++) {
			numbers[i] = std::atoi(argv[i + 1]);
		}
		close(pipeEnds1[0]);
		write(pipeEnds1[1], &numbers, sizeof(numbers));
		close(pipeEnds1[1]);
		wait(NULL);
		close(pipeEnds2[1]);
		read(pipeEnds2[0], &numbers, sizeof(numbers));
		close(pipeEnds2[0]);
		if (secondChild != 0) {
			wait(NULL);
			close(pipeEnds4[1]);
			read(pipeEnds4[0], &median, sizeof(median));
			close(pipeEnds4[0]);
			std::cout << "Sorted array: ";
			for (int i = 0; i < 5; i++) {
				std::cout << numbers[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "Median: " << median << std::endl;
		}
		else {
			close(pipeEnds3[1]);
			read(pipeEnds3[0], &numbers, sizeof(numbers));
			close(pipeEnds3[0]);
			close(pipeEnds4[0]);
			write(pipeEnds4[1], &numbers[2], sizeof(numbers[2]));
			close(pipeEnds4[1]);
		}
	}
	else {
		close(pipeEnds1[1]);
		read(pipeEnds1[0], &numbers, sizeof(numbers));
		close(pipeEnds1[0]);
		std::sort(numbers, numbers + (sizeof(numbers) / sizeof(numbers[0])));
		close(pipeEnds2[0]);
		write(pipeEnds2[1], &numbers, sizeof(numbers));
		close(pipeEnds2[1]);
		close(pipeEnds3[0]);
		write(pipeEnds3[1], &numbers, sizeof(numbers));
		close(pipeEnds3[1]);
	}
	return 0;
}