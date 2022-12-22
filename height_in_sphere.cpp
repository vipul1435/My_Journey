#include<bits/stdc++.h>
# define dd long double 
using namespace std;

int main() 
{
   long  double V,R;
    cin>>R>>V;
   long  double a, b, c, d;
  b=(dd)-3*R;
  c=0;
  d=(long double)(3*V)/(3.1415926299999999999999999999999999999999999999);
    
   long  double disc, q, r, dum1, s, t, term1, r13;
    q = (dd)(3.0*c - (b*b))/9.0;
    r =(dd) (-(27.0*d) + b*(9.0*c - 2.0*(b*b)));
    r =(dd)(r/ 54.0);
    disc =(dd) (q*q*q + r*r);
    term1 =(dd) (b/3.0);
    
    long double x1_real, x2_real, x3_real;
    long double x2_imag, x3_imag;
    string x2_imag_s, x3_imag_s;
    if (disc > 0)   
    {
        s =(dd)((dd) r +(dd) sqrt(disc));
        s = s<0 ?(dd) -cbrt(-s) :(dd) cbrt(s);
        t = (dd)(r - (dd)sqrt(disc));
        t = t<0 ?(dd) -cbrt(-t) :(dd) cbrt(t);
        x1_real =(dd) (-term1 + s + t);
        term1 +=(dd) (s + t)/2.0;
        x3_real = x2_real =(dd) -term1;
        term1 =(dd) sqrt(3.0)*(-t + s)/2;
        x2_imag = term1;
        x3_imag = -term1;
        x2_imag_s =  " + "+ to_string(x2_imag) + "i";
        x3_imag_s =  " - "+ to_string(x2_imag) + "i";
    } 
    else if (disc == 0) 
    { 
        x3_imag = x2_imag = 0;
        r13 = r<0 ? -cbrt(-r) : cbrt(r);
        x1_real =(dd) (-term1 + (dd)2.0*r13);
        x3_real = x2_real = (dd)(-(r13 + term1));
    }
   
    else
    {
        x3_imag = x2_imag = 0;
        q = -q;
        dum1 = q*q*q;
        dum1 = acos(r/sqrt(dum1));
        r13 = 2.0*sqrt(q);
        x1_real =(dd) (-term1 +(dd) r13*(dd)cos((dd)dum1/3.0));
        x2_real = (dd)(-term1 +(dd) r13*(dd)cos((dd)(dum1 + 2.0*M_PI)/3.0));
        x3_real = (dd)(-term1 + (dd) r13*(dd)cos((dd)(dum1 + 4.0*M_PI)/3.0));
    }
    dd ans=1.7976931348623157E+308;
   long double ans1=x1_real;
   if(ans1>0)
   {
       ans=min(ans1,ans);
   }
       long double ans2= x2_real;
        if(ans2>0)
   {
       ans=min(ans2,ans);
   }
           long double ans3=  x3_real;
            if(ans3>0)
   {
       ans=min(ans3,ans);
   }
//    ans+=0.00000005;
//    cout<<ans<<endl;
    // unsigned long long temp=ans*(1e7);
    // ans=temp/(1e7);
    // cout<<ans;
           cout<<fixed<<setprecision(7)<<ans<<endl;
    
    return 0; 
}