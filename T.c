#include <stdio.h> 
#include <conio.h>
#include <windows.h>

void egg(char* somethingrelevant){
	fgets(somethingrelevant, 261, stdin);
}

int main(int argc, char** argv){
	FILE * file;
	file = fopen (argv[1], "r");
	int code_lenght = 128;
	char code[code_lenght];
	int tape_length = 16;
	unsigned char tape[tape_length];
	int pointer = 0;
	int index = 0;
	int cycle = 0;
	int imp;
	int STR_MEM_LOC;
	int STR_CYC_CYL;
	unsigned char temp_mem;
	egg(code);
	while (pointer < tape_length){
		tape[pointer] = 0;
		pointer++;
	} pointer = 0;
	while (1){
		if (index >= code_lenght){
			return 0;
		} else {
			index++;
		}
		if (cycle > 12){
			cycle = 0;
		} 
		switch(code[index]){
				case ('o'):
					cycle++;
					break;    
				case ('r'):
						switch (cycle){
							case 0:
								return 0;							//Zero, ends program
								break;
							case 1:
								printf("%c", temp_mem);		//equivalent to BF "."
								break;
							case 2:
								pointer++;							//equivalent to > in BF
								break;
							case 3:
								pointer--;							//equivalent to < in BF
								break;
							case 4:
								imp=getchar();
								tape[pointer] = (int)imp;			//equivalent to "," in BF
								break;
							case 5:
								tape[pointer]++;
								break;
							case 6:
								tape[pointer]--;
								break;
							case 7:
								STR_MEM_LOC = pointer;
								STR_CYC_CYL = cycle;
								break;
							case 8:
								if (tape[pointer] != 0){
									cycle = STR_CYC_CYL;
									pointer = STR_MEM_LOC;
								} 
								break;
							case 9:
								temp_mem = tape[pointer];
								break;
							case 10:
								tape[pointer] = temp_mem;
								break;
							case 11:
								printf("%d \n", tape[pointer]);
								break;
							case 12:
								Beep(temp_mem * 10, tape[pointer] * 10);
								break;								
						}
					cycle++;
					break;
			}       
		}
}
