// get_request.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Prog.h"

int main()
{
   Client* cli =  new Client("ip-api.com","/json/");
   
   std::string resp =  cli->GetResponce("google.com");

   std::cout << resp << std::endl;

    system("pause");
}


