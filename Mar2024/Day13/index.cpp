int pivotInteger(int n) {
        if(n==1) return 1;
        float x=2*n - (float)sqrt((2*(n*n))+2*n);
        if(fmod(x,2.0)!=0.0) return -1;
        return (int)(n-(x/2));
    }