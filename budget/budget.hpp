#pragma once

#include <string>
#include <vector>

class Budget final {
public:
    explicit Budget(const std::vector<std::string>& path_list, double amount);

	const std::vector<std::string>& getPathList() const noexcept;
	double getAmount() const noexcept;

private:
	std::vector<std::string> path_list;
	double amount;
};