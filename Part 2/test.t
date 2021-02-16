/% comment
    ong comment%/
func foo1(a,b,c:int;z:char) return bool
{
    var c1:char;
    var res:bool;
    {
        var x,b:char;
        var y:int;
        b = '&';
        /%a=x;%/
        /%b=8;%/
        /%a=(y*7)/a-y;%/
        /%a=(y*7)/b-y;%/
        /%a=(y*7)/a-c1;%/
        /%res = (b==c)&&(y>a);%/
        /%res = (b==c1) && (y == a);%/
        /%3+6=9;%/
        /%%x=6;%/
    }
    return res;
}


proc fee1( i,j,k,x:int)
{
    func fee2(l, m, n:int) return bool
    {
        var x, j: bool;
        /%var n:bool;%/
        var k:char;
        k='@';
        i=l+l;
        /%i=j + 1; %/
        /%i=k + 1;%/
        if((k=='*') || (x!=false) && ( l+m < i)) {
            x = l < m;
        }
    return x;
    }
    {
        var x:char;
        var k:bool;k=fee2(5,i,j);
        /%x=fee2(5,i,j);%/
        /% k = fee2(5,i); %/
        /% k = fee2(5,5,j);%/
    }
    /%n=false; %/
   /%x='#'; %/
    x=k;
}

func foo3(i,j,k:int) return int
{
    func square(t:int) return int /% function declaration %/
    {
        var temp:int;
        temp=t*t;
        return temp;
    }
    var total:int; /% variable declaration %/
    var bo:bool;
    /%bo=foo1('#', i, j, k);%/
    /%j=foo2(); %/
    total=square(i+j+k); /% statemets %/
    return total;
}
func foo2() return int
{
    var s1:string[100];
    var s2: string[100];
    var i, j, cnt : int;
    i=0;
    j=0;
    cnt=0;
    while(i < |s1|) {
        while(j < |s2| / 2) {
            if(s1[i] == s2[j]) {
                cnt=cnt*2;
            }
        j=j + 1;
    }
    i=i + 1;
    }
    return cnt;
}

func foo4() return int
{
    {
        var x:int;
        var y:int*;
        x=5;
        y=&x;
        x=6;
        /%
        if( &x == y && ^y == x ) {
        ^y=9;
        }%/
    {
        var x:char*;
        var y: string[10];
        var z: char;
        x=&y[5];
        z=^(x - 5);
        y="barfoo";
        {
            var x:char; 
            var y:int*;
            var z:char*;
            var g:char;
            /%y=&(1 + 3);%/
            /%y=&x;%/
            /%z= & ( & (g)); %/
        }
    }
}
return 0;
}
proc Main()
{
    var a:int;
    a = foo2();
}