#include <iostream>
#include <mysql.h>

int main(){
    MYSQL *connect = mysql_init(NULL);
    
    if(!connect){
        std::cout << "MySQL não foi inicializado pelo sistema de inicialização.\n";
        return 1;
    }

    connect = mysql_real_connect(connect, "localhost", "root", "", "cpp", 0, NULL, 0);

    if(connect){
        std::cout << "Conectado com sucesso ao MySQL!\n";
    }else{
        std::cout << "Falha ao conectar ao banco de dados!\n";
    }
    
    mysql_close(connect);
    
    return 0;
}
// g++ Main.cpp -L'C:\Program Files\MySQL\MySQL Server 8.0\lib' -I'C:\Program Files\MySQL\MySQL Server 8.0\include' -lmysql