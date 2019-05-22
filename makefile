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

$(EXECUTABLE): $(BUILD)Main.o $(BUILD)Graph.o $(BUILD)GraphIO.o $(BUILD)DijkstrasAlgo.o
	$(FLAGSL) $(BUILD)Main.o $(BUILD)Graph.o $(BUILD)GraphIO.o $(BUILD)DijkstrasAlgo.o -o $(EXECUTABLE)

$(BUILD)Main.o: $(SOURCE)Main.cpp $(INCLUDES)Graph.hpp $(INCLUDES)GraphIO.hpp $(INCLUDES)DijkstrasAlgo.hpp
	$(FLAGSO) $(SOURCE)Main.cpp -I$(INCLUDES) -o $(BUILD)Main.o

$(BUILD)Graph.o: $(SOURCE)Graph.cpp $(INCLUDES)Graph.hpp
	$(FLAGSO) $(SOURCE)Graph.cpp -I$(INCLUDES) -o $(BUILD)Graph.o

$(BUILD)GraphIO.o: $(SOURCE)GraphIO.cpp $(INCLUDES)GraphIO.hpp
	$(FLAGSO) $(SOURCE)GraphIO.cpp -I$(INCLUDES) -o $(BUILD)GraphIO.o

$(BUILD)DijkstrasAlgo.o: $(SOURCE)DijkstrasAlgo.cpp $(INCLUDES)DijkstrasAlgo.hpp $(INCLUDES)Graph.hpp
	$(FLAGSO) $(SOURCE)DijkstrasAlgo.cpp -I$(INCLUDES) -o $(BUILD)DijkstrasAlgo.o

clean:
	-$(DELETE) $(BUILD)Main.o $(BUILD)Graph.o $(BUILD)GraphIO.o $(BUILD)DijkstrasAlgo.o $(EXECUTABLE)