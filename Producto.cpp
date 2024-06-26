#include "Producto.h"

Producto::Producto(){

}
Producto::Producto(string categoria, string subcategoria, string idProducto, string nombreProducto, double precio)
{
    this->idProducto = idProducto;
    this->nombreProducto = nombreProducto;
    this->precio = precio;
    this->categoria = categoria;
    this->subcategoria = subcategoria;
}

Producto::~Producto()
{
}

void Producto::setIdProducto(string idProducto)
{
    this->idProducto = idProducto;
}

void Producto::setNombreProducto(string nombreProducto)
{
    this->nombreProducto = nombreProducto;
}

void Producto::setPrecio(int precio)
{
    this->precio = precio;
}

void Producto::setCategoria(string categoria)
{
    this->categoria = categoria;
}

void Producto::setSubCategoria(string subcategoria)
{
    this->subcategoria = subcategoria;
}

string Producto::obtenerIdProducto()
{
    return idProducto;
}

string Producto::obtenerNombreProducto()
{
    return nombreProducto;
}

int Producto::obtenerPrecioProducto()
{
    return precio;
}

string Producto::obtenerCategoria()
{
    return categoria;
}

string Producto::obtenerSubCategoria()
{
    return subcategoria;
}

string Producto::toString(){
    return categoria+","+subcategoria+","+idProducto+","+nombreProducto+","+to_string(precio);
}