#include <gtest/gtest.h>
#include <memory>
#include <filesystem>
#include <fstream>
#include <JsonLogger.h>


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

std::string readFile(std::filesystem::path path)
{
    // Open the stream to 'lock' the file.
    std::ifstream f(path, std::ios::in | std::ios::binary);

    // Obtain the size of the file.
    const auto sz = std::filesystem::file_size(path);

    // Create a buffer.
    std::string result(sz, '\0');

    // Read the whole file into the buffer.
    f.read(result.data(), sz);

    return result;
}

TEST(Creation, Pointer){
    JsonLogger* logger = new JsonLogger("test");

    Json::Value json;
    json["value"] = 0;
    logger->add_datapoint(milliseconds(0), json);

    delete logger;
    logger = nullptr;

    const auto file_contents = readFile("test.json");
    ASSERT_TRUE(file_contents.size() > 0);
}

TEST(Creation, Unique_Pointer){
    std::unique_ptr<JsonLogger> logger = std::make_unique<JsonLogger>("test_unique");
    Json::Value json;
    json["value"] = 0;
    logger->add_datapoint(milliseconds(0), json);
    EXPECT_TRUE(logger);
    logger.reset();
    EXPECT_FALSE(logger);

    const auto file_contents = readFile("test_unique.json");
    ASSERT_TRUE(file_contents.size() > 0);
}
