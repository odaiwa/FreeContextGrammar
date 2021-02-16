func B11(x:int) return int{
	var y:int;
	y=15;
	if(x==140)
    		y=14;
	else
    		y=13;
	return x+y;
} 

proc Main()
{
	var a,b:int;
	a=12;
	while(a<100){
    		b=B11(11);
    		a=a+b;
	}
}

