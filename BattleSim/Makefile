TARGET=battle
OBJECTS=battle.o Field.o Warrior.o Good_Warrior.o Evil_Warrior.o Man.o Elf.o Orc.o Troll.o
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion

$(TARGET): $(OBJECTS)
	g++ $(OBJECTS) -o $(TARGET)

all: clean $(TARGET)

clean:
	/bin/rm -f *.o *~ $(TARGET)

battle.o: battle.cpp Field.h Warrior.h

Field.o: Field.cpp Field.h Warrior.h

Warrior.o: Warrior.cpp Warrior.h Field.h

Good_Warrior.o: Good_Warrior.cpp Good_Warrior.h Warrior.h Field.h

Evil_Warrior.o: Evil_Warrior.cpp Evil_Warrior.h Warrior.h Field.h

Man.o: Man.cpp Man.h Good_Warrior.h Warrior.h Field.h

Elf.o: Elf.cpp Elf.h Good_Warrior.h Warrior.h Field.h

Orc.o: Orc.cpp Orc.h Evil_Warrior.h Warrior.h Field.h

Troll.o: Troll.cpp Troll.h Evil_Warrior.h Warrior.h Field.h

