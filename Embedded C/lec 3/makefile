#@copyright : Mostafa-Elfallal
CC=arm-none-eabi-
CFLAGS=-mthumb -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name =lec3


all: $(Project_name).bin
	@echo "===============Done==============="
	
%.o: %.c
	@echo "===============compiling the $< to get $@ file==============="
	$(CC)gcc -c $(CFLAGS) $(INCS) $< -o $@

#startup.o: startup.s
#	@echo "===============assembling the $< to get $@ file==============="
#	$(CC)as $(CFLAGS) $< -o $@
	


$(Project_name).elf: $(OBJ) $(AsOBJ)
	@echo "===============linking to get the $@ file==============="
	$(CC)ld -T linker.ld $(INCS) $(OBJ) $(AsOBJ) -o $@ -Map=mapfile.map
	
$(Project_name).bin: $(Project_name).elf
	@echo "===============extracting the get binary file :$@==============="
	$(CC)objcopy -O binary $< $@

clean_all:
	@echo "===============deleting all project files==============="
	rm *.o *.elf *.bin
	
clean:
	@echo "===============deleting the elf and bin files==============="
	rm *.elf *.bin