#include "inireader.hpp"

#include <fstream>


namespace necfs {

static bool IsSection(const std::string & str) {
  if (str.front() != '[' || str.back() != ']') {
    return false;
  }
  for (int i = 1; i < (int)str.size() - 1; i++) {
    if (str[i] == '[' || str[i] == ']') {
      return false;
    }
  }
  return true;
}

std::string ParseSection(const std::string & str) {
  return str.substr(1, str.size() - 2);
}

std::string Trim(const std::string & trim_str) {
  int l = 0, r = trim_str.size() - 1;
  while (l < (int)trim_str.size() && trim_str[l] == ' ') {
    ++l;
  }
  while (r >= 0 && trim_str[r] == ' ') {
    --r;
  }
  if (l > r) {
    return "";
  }
  return trim_str.substr(l, r - l + 1);
}

void ParseKeyValue(const std::string & line, std::string * k, std::string * v) {
  bool isk = true;
  for (int i = 0; i < (int)line.size(); i++) {
    // ignore marks
    if (line[i] == ';' || line[i] == '#') break;
    if (line[i] == '=') {
      isk = false;
      continue;
    } else {
      if (isk) {
        k->push_back(line[i]);
      } else {
        v->push_back(line[i]);
      }
    }
  }
  *k = Trim(*k);
  *v = Trim(*v);
}

std::string CutMarkAndTrim(const std::string & line) {
  std::string r;
  for (char c : line) {
    if (c != ';' || c != '#') {
      r.push_back(c);
    } else {
      break;
    }
  }
  return Trim(r);
}

INIReader::INIReader() {
  conf_.clear();
}

int INIReader::ReadFile(const std::string & filename) {
  std::ifstream ifs;
  ifs.open(filename, std::ios::in);
  if (!ifs.is_open()) {
    return -1;
  }
  std::string line;
  std::string Section = "";
  while (std::getline(ifs, line)) {
    if (line.empty()) continue;
    line = CutMarkAndTrim(line);
    if (IsSection(line)) {
      Section = ParseSection(line);
    } else {
      std::string key, value;
      ParseKeyValue(line, &key, &value);
      conf_[Section][key] = value;
    }
  }
  return 0;
}

std::string INIReader::GetItem(const std::string & section, const std::string & tag) const {
  auto its = conf_.find(section);
  if (its != conf_.end()) {
    auto itt = its->second.find(tag);
    if (itt != its->second.end()) {
      return itt->second;
    } else {
      return "";
    }
  } else {
    return "";
  }
}

std::vector<std::string> INIReader::GetSections() const {
  std::vector<std::string> sections;
  for (const auto & p : conf_) {
    sections.push_back(p.first);
  }
  return sections;
}

std::vector<std::string> INIReader::GetTags(const std::string & section) const {
  std::vector<std::string> tags;
  auto it = conf_.find(section);
  if (it == conf_.end()) {
    return tags;
  } else {
    for (const auto & p : it->second) {
      tags.push_back(p.first);
    }
  }
  return tags;
}

INIReader::~INIReader() {}


} // namespace necfs
