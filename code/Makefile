CC = gcc
CFLAGS=-Wall -Wextra
PROGRAM_1=L1Program.c
TARGET_1=L1Cache
PROGRAM_2=L2Program.c
TARGET_2=L2Cache
PROGRAM_3=L2WProgram.c
TARGET_3=L2WCache

all:
	$(CC) $(CFLAGS) $(PROGRAM_1) ./4.1/$(TARGET_1).c -o $(TARGET_1)
	$(CC) $(CFLAGS) $(PROGRAM_2) ./4.2/$(TARGET_2).c -o $(TARGET_2)
	$(CC) $(CFLAGS) $(PROGRAM_3) ./4.3/$(TARGET_3).c -o $(TARGET_3)

clean:
	rm -f $(TARGET_1) $(TARGET_2) $(TARGET_3)