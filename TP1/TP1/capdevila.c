
int suma(int a, int b){

    int result;
    result = a + b;
    return result;

}




int resta (int a, int b){

    int result;
    result = a - b;
    return result;
}


int multiplicar (int a, int b){

    int result;
    result = a * b;
    return result;
}


float dividir (float a, float b){

    float resultDiv;
    resultDiv = a / b;
    return resultDiv;
}



long long factorizar(int a){

    long long result = 1;

    for (int i = a; i >= 1; i-- ){
        result *= i;
    }
    return result;
}
