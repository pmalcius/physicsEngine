CXX       := g++
CXXFLAGS  := -std=c++17 -Wall -Wextra

# Works for both Intel (/usr/local) and Apple Silicon (/opt/homebrew)
BREW_PREFIX := $(shell brew --prefix 2>/dev/null || echo /usr/local)

INCLUDES  := -I include -I$(BREW_PREFIX)/include
LDFLAGS   := -L$(BREW_PREFIX)/lib
LDLIBS    := -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR   := src
BUILD_DIR := build
TARGET    := physicsEngine

SRCS := \
	$(SRC_DIR)/main.cpp \
	$(SRC_DIR)/core/PhysicsEngine.cpp \
	$(SRC_DIR)/core/RigidBody.cpp \
	$(SRC_DIR)/core/Vector3D.cpp

OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

run: all
	./$(TARGET)
