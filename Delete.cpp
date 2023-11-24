#include <iostream>
#include <mysql.h>
#include <string.h>

int main(){
    MYSQL* connect = mysql_init(NULL);

    std::string del = {};
    std::string id;

    connect = mysql_real_connect(connect, "localhost", "root", "", "cpp", 0, NULL, 0);
    try
    {
        if(!connect){
            throw connect;
            return 1;
        }

        MYSQL_RES* res_set; // Armazena os dados do mysql
        MYSQL_ROW row;

        std::cout << "Informe o id a ser deletado: ";
        std::getline(std::cin, id);

        del = "DELETE FROM crudcpp WHERE id=" + id;

        bool query_state = mysql_query(connect, del.c_str());

        if(!query_state){
            std::cout << "Dados deletados com sucesso!" << std::endl;
        }else{
            std::cout << "Error ao deletar dados: " << mysql_error(connect) << std::endl;
        }

        mysql_close(connect);
        return 0;
    }
    catch(...)
    {
        std::cout << "Falha ao conectar.\n";
    }
}
// g++ Delete.cpp -L'C:\Program Files\MySQL\MySQL Server 8.0\lib' -I'C:\Program Files\MySQL\MySQL Server 8.0\include' -lmysql -o delete