# Tabla de Contenidos
1. [[#Búsqueda Binaria]]
2. [[#Programación Dinámica]]
3. [[#Segment Tree]]
# Búsqueda Binaria
- Dado un arreglo ordenado, el algoritmo de búsqueda binaria busca un elemento o condición en el arreglo en tiempo $O(\log n)$.
- Su implementación en `C++`:
```c++
while(l<=h){
	m = l+(h-l)/2;
	if (m>h) h = m+1;
	else l = m-1;
}
```
- También si queremos encontrar un número en $\mathbb{R}$ podemos hacer:
```c++
double EPS = 1e-6; 
while(r-l > EPS){ 
	//... lo mismo de antes 
}
```
## Referencias
1. [Búsqueda binaria - Programación Competitiva UChile (progcomp.cl)](https://uchile.progcomp.cl/apunte/paradigmas_de_resolucion/busqueda_binaria/)
# Programación Dinámica
- La programación dinámica es una técnica de optimización que consiste en dividir un problema en subproblemas de manera que cada subproblema se resuelve solo una vez, y se almacena su solución para no tener que volver a calcularla cada vez que se necesite.
- Ejemplo de Fibonacci:
```c++
int fib(int n){
	if (n==0) return 0;
	if (n==1) return 1;
	return fib(n-1)+fib(n-2);
}
```
- Este algoritmo tiene una complejidad de $O(2^n)$, pero si lo hacemos con programación dinámica:
```c++
vector<int> dp(1000,-1);
int fib(int n){
	if (n==0) return 0;
	if (n==1) return 1;
	if (dp[n]!=-1) return dp[n];
	return dp[n] = fib(n-1)+fib(n-2);
}
```
- La complejidad de este algoritmo es $O(n)$.
## Referencias
1. [Programación dinámica - Programación Competitiva UChile (progcomp.cl)](https://uchile.progcomp.cl/apunte/paradigmas_de_resolucion/programacion_dinamica/)
# Segment Tree
- Es un algoritmo que sirve para hacer consultas sobre las propiedades de un arreglo en un rango específico.
- Ejemplo: Veamos como extraer el mínimo de un arreglo en un rango específico.
[![Segment Tree - GeeksforGeeks](https://media.geeksforgeeks.org/wp-content/cdn-uploads/segment-tree1.png)