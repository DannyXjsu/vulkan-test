#pragma once

#include "../app/vt_device.hpp"

#include <string>
#include <vector>
#include <vulkan/vulkan_core.h>

namespace vt{

    struct PipelineConfigInfo {};

    class VTPipeline {

        public:
        VTPipeline(
            VTDevice &device,
            const std::string& vertFilepath,
            const std::string& fragFilepath,
            const PipelineConfigInfo& configInfo);
        ~VTPipeline() {}

        //VTPipeline(const VTPipeline&) = delete;
        VTPipeline& operator=(const VTPipeline&) = delete;

    static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

        private:
            static std::vector<char> readFile(const std::string& filepath);

            void createGraphicsPipeline(
                const std::string& vertFilepath,
                const std::string& fragFilepath,
                const PipelineConfigInfo& configInfo);

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        VTDevice& vtDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
}