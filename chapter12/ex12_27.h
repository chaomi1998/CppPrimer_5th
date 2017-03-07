#ifndef EX12_27_H
#define EX12_27_H

#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <memory>
#include <string>
class QueryResult;
class TextQuery;
std::ostream& print(std::ostream&, const QueryResult&, const TextQuery&);

class QueryResult {
public:
	QueryResult(const std::string &w, std::shared_ptr<std::set<unsigned>> p): word(w), lptr(p) { }
	friend std::ostream& print(std::ostream&, const QueryResult&, const TextQuery&);
	
private:
	std::shared_ptr<std::set<unsigned>> lptr;
	std::string word;
};

class TextQuery {
public:
	friend class QueryResult;
	friend std::ostream& print(std::ostream&, const QueryResult&, const TextQuery&);
	TextQuery(std::ifstream &infile) {
		std::string line;
		while (getline(infile, line)) {
			data.push_back(line);
			make_index();
		}
	}
	QueryResult query(const std::string &) const;
private:
	void make_index();
	std::vector<std::string> data;
	std::map<std::string, 
			 std::shared_ptr<std::set<unsigned>>> word_count;
};

void TextQuery::make_index()
{
	for (std::size_t i = 0; !data.empty() && i != data.size(); ++i) {
		std::istringstream line(data[i]);
		std::string word;
		while (line >> word) {
			auto &lines= word_count[word];
			if (!lines) {
				lines.reset(new std::set<unsigned>);
			}
			lines->insert(i);
		}
	}
}



QueryResult TextQuery::query(const std::string &wd) const
{
	auto result = word_count.find(wd);
	if (result != word_count.end()) {
		return QueryResult(wd, result->second);
	}
	else {
		return QueryResult(wd, std::shared_ptr<std::set<unsigned>>(new std::set<unsigned>));
	}
}

#endif