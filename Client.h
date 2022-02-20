#pragma once


class Client {
public:	
	Client(std::string Api_string, std::string Api_Arguments) {
		this->Api_Arguments = Api_Arguments;
		this->Api_string = Api_string;
	}
	std::string GetResponce(std::string);
private:
	std::string Api_string;
	std::string Api_Arguments;
};