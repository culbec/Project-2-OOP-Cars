#pragma once

#include <string>
#include <utility>

using std::string;

class DTO{
private:
    // model + count number
    string model;
    unsigned int count;

public:
    DTO() = default;
    DTO(string modelM, unsigned int countM): model{std::move(modelM)}, count{countM} {}

    const string& getModel() const;

    unsigned int getCount() const;
};