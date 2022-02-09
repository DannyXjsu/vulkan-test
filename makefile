BUILD_DIR := ./build
SRC_DIRS := ./src

CC = g++
SHADERC = glslc
CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

vulkan-test: $(SRC_DIRS)/*.cpp $(SRC_DIRS)/*/*.cpp
	mkdir -p $(BUILD_DIR)
	$(SHADERC) $(SRC_DIRS)/shaders/simple_shader.vert -o $(SRC_DIRS)/shaders/simple_shader.vert.spv
	$(SHADERC) $(SRC_DIRS)/shaders/simple_shader.frag -o $(SRC_DIRS)/shaders/simple_shader.frag.spv
	
	mkdir -p $(BUILD_DIR)/shaders
	cp $(SRC_DIRS)/shaders/*.spv $(BUILD_DIR)/shaders

	$(CC) $(CFLAGS) -o $(BUILD_DIR)/VulkanTest $(SRC_DIRS)/*.cpp $(SRC_DIRS)/*/*.cpp $(LDFLAGS)

.PHONY: test clean shader

test: vulkan-test
	$(BUILD_DIR)/VulkanTest
clean:
	rm -r $(BUILD_DIR)