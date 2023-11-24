#include <iostream>
#include <mysql.h>
#include <string.h>

int main(){
    MYSQL* connect = mysql_init(NULL);

    std::string create = {};
    std::string nome, mail;

    connect = mysql_real_connect(connect, "localhost", "root", "", "cpp", 0, NULL, 0);
    try
    {
        if(!connect){
            throw connect;
            return 1;
        }

        MYSQL_RES* res_set; // Armazena os dados do mysql
        MYSQL_ROW row;

        std::cout << "Informe o nome: ";
        std::getline(std::cin, nome);
        std::cout << "Informe o e-mail: ";
        std::getline(std::cin, mail);

        create = "INSERT INTO crudcpp VALUES(NULL, '" + nome + "', '" + mail + "')";

        bool query_state = mysql_query(connect, create.c_str());

        if(!query_state){
            std::cout << "Dados inseridos com sucesso!" << std::endl;
        }else{
            std::cout << "Error ao inserir dados: " << mysql_error(connect) << std::endl;
        }

        mysql_close(connect);
        return 0;
    }
    catch(...)
    {
        std::cout << "Falha ao conectar.\n";
    }
}
// g++ Create.cpp -L'C:\Program Files\MySQL\MySQL Server 8.0\lib' -I'C:\Program Files\MySQL\MySQL Server 8.0\include' -lmysql -o create