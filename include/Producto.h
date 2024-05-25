//#include <iostream>
#include <string>

using namespace std;

class Producto {

    private:
        string idProducto;
        string nombreProducto;
        int precio;
        string categoria;
        string subcategoria;

    public:
        Producto(string idProducto, string nombreProducto, int precio, string categoria, string subcategoria);
        ~Producto();
        void setIdProducto(string idProducto);
        void setNombreProducto(string nombreProducto);
        void setPrecio(int precio);
        void setCategoria(string categoria);
        void setSubCategoria(string subcategoria);
        string obtenerIdProducto();
        string obtenerNombreProducto();
        int obtenerPrecioProducto();
        string obtenerCategoria();
        string obtenerSubCategoria();


};