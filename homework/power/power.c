int power(int a, int b){
    int result = 1;
    int i;
    for  (i = b; i > 0; i--)
    {
        result = a * result; 
    }   
}