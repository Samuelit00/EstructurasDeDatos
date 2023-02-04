#!/usr/bin/env python3
#Samuel Francisco Moncayo Moncayo
#Ejercicio  #1

def verificarDiagonales(mat):
    #Función que verifica que las diagonales de una matriz sean iguales
    indiceMatriz = 0
    indiceLista = 0
    indiceInverso = -1
    while indiceLista <= len(mat)-1:
        #Ciclo que recorre los indices principales de la matriz
        if mat[indiceMatriz][indiceLista] == mat[indiceMatriz][indiceInverso]:
            #Verifica que el indice de determinada lista, sea igual a su inverso
            #Aumentando el indice para recorrer la diagonal de manera normal y inversa
            indiceMatriz += 1
            indiceLista += 1
            indiceInverso -= 1
        else:
            return False
    return True

print(verificarDiagonales([[11, 23, 76, 34, 11],
[14, 30, 92, 30, 101],
[12, 45, 58, 92, 22],
[74, 56, 49, 56, 100],
[99, 5, 28, 47, 99]]))

#Ejercicio #2

def esCapicua(list1):
    #Función que verifica si el valor de entrada [list] es igual de izquierda a derecha
    indiceList = 0
    inversoIndice = -1
    while indiceList < len(list1):
        #Ciclo que recorre los indices de la lista
        if list1[indiceList] == list1[inversoIndice]:
            #Verifica si el primer valor y el ultimo valor de la lista son iguales y asi con las demas parejas
            indiceList += 1
            inversoIndice -= 1
        else:
            return False
    return True
print(esCapicua([3,5,3,4,3]))

#Ejercicio #3A

def diferenciaListas(list1,list2):
    difList = list1.copy()
    indice = 0
    while indice < len(list1):
        #Ciclo que recorre la lista 1
        acum1 = list1[indice]
        indice2 = 0
        indice += 1
        while indice2 < len(list2):
            #Ciclo que recorre toda la lista 2 antes de cambiar el valor del indice de la lista 1
            acum2 = list2[indice2]
            indice2 += 1
            if acum1 == acum2:
                #Verifica si el valor del indice de la lista 1 es igual a algun valor de la lista 2
                var = True
                while var != True:
                    difList.remove(acum1)
                    list2.remove(acum2)
                    var = False
    print(difList)

diferenciaListas([41, 22, 31, 15, 13, 12, 33, 19],[40, 10, 22, 12, 33, 33, 33])

#Ejercicio #3B

def lectorDatos():
    lista1 = []
    lista2= []
    difLista = []
    numEjecuciones = int(input(""))
    j = 0
    while j < numEjecuciones:
        cantidadList = int(input(""))
        #Delimita la cantidad de elementos de la lista a digitar
        x = 0
        while x < cantidadList:
            #Ciclo que permite digitar todos los elmentos mencionados en una lista 1
            lista1.append(int(input("")))
            x += 1
        cantidadList2 = int(input(""))
        n = 0
        while n < cantidadList2:
            #Ciclo que permite digitar todos los elmentos mencionados en la variable CantidadList2 en una lista 2
            lista2.append(int(input("")))
            n += 1
        j += 1
        difLista = diferenciaListas(lista1,lista2)
        #Llama a la función diferenciaListas para encontrar las diferencias de 2 listas y igualarlos en una variable [list]
        #Reanuda el ciclo para tomar diferentes listas
        sinCorchetes = str(difLista)[1:-1]
        print(sinCorchetes)

lectorDatos()

#Ejercicio 4

def mostrarPrimos(cantidadNum):
    sumalist = []
    print("Numeros primos entre 1 y", cantidadNum, ":")
    for numeroPrimo in range(2, cantidadNum):
            num = True
            for divisor in range(2, numeroPrimo):
                #Evalua cada divisor del numero requerido para determinar si su division es exacta con alguno de ellos
                #En caso de no ser exacta el numero es considerado primo
                if numeroPrimo % divisor == 0:
                    num = False
            if num is True:
                print("--> %d,"%(numeroPrimo)) 
                if numeroPrimo < 10:
                    #Delimita los primeros numeros primos que la suma de sus digitos es un numero primo
                    sumalist.append(numeroPrimo) 
                else:
                    contadorPrimo = numeroPrimo
                    resultado = 0
                    while (contadorPrimo != 0):
                        #Descompone el numero primo, para extraer sus digitos y sumarlos con el acumulador
                        resultado = resultado + (contadorPrimo % 10)
                        contadorPrimo = contadorPrimo // 10
                    num2 = True
                    for x in range(2, resultado):
                        if resultado % x == 0:
                            num2 = False
                    if num2 == True:
                        #En caso de que la suma de sus digitos sea un numero primo es añadido a una lista
                        sumalist.append(numeroPrimo)     
    print("Números entre 1 y" ,cantidadNum ,"con suma de dígitos con valor primo:")   
    listaStr = str(sumalist)[1:-1]
    print(listaStr)
mostrarPrimos(100)

#Ejercicio #5

def sumarValoresMatriz(mat):



