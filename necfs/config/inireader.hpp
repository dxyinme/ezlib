#ifndef EZ_LIB_NECFS_CONFIG_INIREADER_HPP_
#define EZ_LIB_NECFS_CONFIG_INIREADER_HPP_

#include <string>
#include <vector>
#include <unordered_map>

namespace necfs {

class INIReader {
public:
  explicit INIReader();
  int ReadFile(const std::string & filename);
  std::string GetItem(const std::string & section, const std::string & tag) const;
  std::vector<std::string> GetSections() const;
  std::vector<std::string> GetTags(const std::string & section) const;
  ~INIReader();
private:
  std::unordered_map<
    std::string, 
    std::unordered_map<std::string, std::string>
  > conf_;
};

} // namespace necfs


#endif