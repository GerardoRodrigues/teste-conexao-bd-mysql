#include <iostream>
#include <mysql.h>

int main(){
    MYSQL *connect = mysql_init(NULL);
    !connect ? std::cerr << "MySQL n foi conectado" : std::cout << "MySQL conectado com sucesso";

    mysql_close(connect);
    return 0;
}