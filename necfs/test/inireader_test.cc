#include <gtest/gtest.h>
#include "necfs/config/inireader.hpp"

class INIReaderTest : public testing::Test {
public:
  void SetUp() override {}
  void TearDown() override {}

  void ConstTestFunc(const necfs::INIReader & r) {
    EXPECT_EQ("/xxx/test_info/leveldb_dir/", r.GetItem("Db", "leveldb_dir"));
    EXPECT_EQ("User", r.GetItem("Db", "Table1"));
    EXPECT_EQ("Kaster", r.GetItem("Db", "Table2"));
    EXPECT_EQ("kkki", r.GetItem("Db", "Table3"));
    EXPECT_EQ("auto_id|int64|0", r.GetItem("User", "n1"));
    EXPECT_EQ("test_id|uint64|0", r.GetItem("User", "n2"));
    EXPECT_EQ("", r.GetItem("xx", "none"));
  }

  const char * normal_test_file_{"normal_test.conf"};
  const char * empty_test_file_{"empty_test.conf"};
  const char * normal_test_with_mark_file_{"normal_test_with_mark.conf"};
};

TEST_F(INIReaderTest, normal_test) {
  necfs::INIReader ini_reader;
  int ret = ini_reader.ReadFile(normal_test_file_);
  EXPECT_EQ(ret, 0);
  ConstTestFunc(ini_reader);
}

TEST_F(INIReaderTest, read_empty_file) {
  necfs::INIReader ini_reader;
  int ret = ini_reader.ReadFile(empty_test_file_);
  EXPECT_EQ(ret, 0);
}

TEST_F(INIReaderTest, read_normal_file_with_mark) {
  necfs::INIReader ini_reader;
  int ret = ini_reader.ReadFile(normal_test_with_mark_file_);
  EXPECT_EQ(ret, 0);
  ConstTestFunc(ini_reader);
}