ifeq ($(OS), Windows NT)
	BIN := Bin\\
	BUILD := Build\\
	SOURCE := Source\\
	INCLUDES := Includes\\
	DELETE := del
	EXECUTABLE := $(BIN)ShortestPath.exe
else
	BIN := Bin/
	BUILD := Build/
	SOURCE := Source/
	INCLUDES := Includes/
	DELETE := rm
	EXECUTABLE := $(BIN)ShortestPath
endif

FLAGSL := g++ -g -std=c++11 -Wall -Wextra -Wpedantic
FLAGSO := g++ -g -c -std=c++11 -Wall -Wextra -Wpedantic

all: $(EXECUTABLE)

$(EXECUTABLE): $(BUILD)Main.o $(BUILD)PriorityQueue.o $(BUILD)Graph.o $(BUILD)GraphIO.o $(BUILD)DijkstrasAlgo.o
	$(FLAGSL) $(BUILD)Main.o $(BUILD)PriorityQueue.o $(BUILD)Graph.o $(BUILD)GraphIO.o $(BUILD)DijkstrasAlgo.o -o $(EXECUTABLE)

$(BUILD)Main.o: $(SOURCE)Main.cpp
	$(FLAGSO) $(SOURCE)Main.cpp -o $(BUILD)Main.o

$(BUILD)PriorityQueue.o: $(INCLUDES)PriorityQueue.h
	$(FLAGSO) $(SOURCE)PriorityQueue.h -o $(BUILD)PriorityQueue.o

$(BUILD)Graph.o: $(SOURCE)Graph.cpp
	$(FLAGSO) $(SOURCE)Graph.cpp -o $(BUILD)Graph.o

$(BUILD)GraphIO.o: $(SOURCE)GraphIO.cpp
	$(FLAGSO) $(SOURCE)GraphIO.cpp -o $(BUILD)GraphIO.o

$(BUILD)DijkstrasAlgo.o: $(SOURCE)DijkstrasAlgo.cpp
	$(FLAGSO) $(SOURCE)DijkstrasAlgo.cpp -o $(BUILD)DijkstrasAlgo.o

clean:
	-$(DELETE) $(BUILD)Main.o $(BUILD)PriorityQueue.o $(BUILD)Graph.o $(BUILD)GraphIO.o $(BUILD)DijkstrasAlgo.o $(EXECUTABLE)