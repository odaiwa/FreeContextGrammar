func odai(x:real) return int
{
    var a:int;
    a=23;
    if(a==23)
    	a=10;
    else
    	a=19;
    return a;
}

proc Main()
{
    var i,a,c,b:int;
    a=0;
    while(a<0)
    {
        b=odai(3.14);
        a=a+b;
    }
}

