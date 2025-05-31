#pragma once

#include <string>
#include <vector>

class Budget final {
public:
    Budget();

	const std::vector<std::string>& getPathList() const noexcept;
	double getAmount() const noexcept;

	void addPath(const std::string& path);
	void setAmount(double amount) noexcept;

private:
	std::vector<std::string> path_list;
	double amount;
};