#include <iostream>
#include <mysql.h>
#include <string.h>

int main(){
    MYSQL* connect = mysql_init(NULL);

    std::string update = {};
    std::string campo, mail, id, novo;

    connect = mysql_real_connect(connect, "localhost", "root", "", "cpp", 0, NULL, 0);
    try
    {
        if(!connect){
            throw connect;
            return 1;
        }

        MYSQL_RES* res_set; // Armazena os dados do mysql
        MYSQL_ROW row;

        std::cout << "Informe o id a ser atualizado: ";
        std::getline(std::cin, id);
        std::cout << "Informe o campo a ser atualizado [nome/mail]: ";
        std::getline(std::cin, campo);
        std::cout << "Informe o novo dado: ";
        std::getline(std::cin, novo);

        update = "UPDATE crudcpp SET " + campo + "='" + novo + "' WHERE id=" + id;

        bool query_state = mysql_query(connect, update.c_str());

        if(!query_state){
            std::cout << "Dados atualizados com sucesso!" << std::endl;
        }else{
            std::cout << "Error ao atualizar dados: " << mysql_error(connect) << std::endl;
        }

        mysql_close(connect);
        return 0;
    }
    catch(...)
    {
        std::cout << "Falha ao conectar.\n";
    }
}
// g++ Update.cpp -L'C:\Program Files\MySQL\MySQL Server 8.0\lib' -I'C:\Program Files\MySQL\MySQL Server 8.0\include' -lmysql -o update