% Poisson equation -\nabla² u = f with dirichlet conditions u = 0

close all;
clear all;

mx = 5;
hx = 1/(mx-1);

x_p = linspace(0,1,(mx));

for i=1:mx
     f(1,i) = x_p(i)^3;
    uex(1,i) = x_p(i)^5/20;
end

f(1,1) = 0;
f(1,mx) = 0;

A = eye(mx);

for i = 1:mx
      A(i,i) = 2/hx^2;
end
for i = 2:mx
      A(i,i-1) = -1/hx^2;
      A(i-1,i) = -1/hx^2;
end
f
u = A\f'

spy(A)