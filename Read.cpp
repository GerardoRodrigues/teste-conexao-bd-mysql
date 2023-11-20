#include <iostream>
#include <mysql.h>

int main(){
    MYSQL* connect = mysql_init(NULL);

    connect = mysql_real_connect(connect, "localhost", "root", "", "cpp", 0, NULL, 0);
    try
    {
        if(!connect){
            throw connect;
            return 1;
        }

        MYSQL_RES* res_set; // Armazena os dados do mysql
        MYSQL_ROW row;

        mysql_query(connect, "SELECT * FROM crudcpp");
        res_set = mysql_store_result(connect);

        while((row = mysql_fetch_row(res_set)) != NULL){
            std::cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << "\n";
        }

        mysql_close(connect);
        return 0;
    }
    catch(...)
    {
        std::cout << "Falha ao conectar.\n";
    }
}
// g++ Read.cpp -L'C:\Program Files\MySQL\MySQL Server 8.0\lib' -I'C:\Program Files\MySQL\MySQL Server 8.0\include' -lmysql -o read