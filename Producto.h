#pragma once

#include <iostream>
#include <string>

using namespace std;

class Producto {

    private:
        string idProducto;
        string nombreProducto;
        double precio;
        string categoria;
        string subcategoria;

    public:
        Producto();
        Producto(string categoria, string subcategoria, string idProducto, string nombreProducto, double precio);
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
        string toString();
};