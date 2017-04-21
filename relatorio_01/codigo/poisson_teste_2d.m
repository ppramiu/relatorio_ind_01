% Poisson equation -\nabla² u = f with dirichlet conditions u = 0

close all;
clear all;

mx = 4;
my = 3;
hx = 1/(mx-1);
hy = 1/(my-1);

x_p = linspace(0,1,(mx));
y_p = linspace(0,1,(my));
f = zeros(1,mx*my);

for i=1:mx
  for j=1:my
  if (i ~= 1 & i ~= mx & j ~= 1 & j ~= my)
    f(1,i + (j-1)*mx) = 2*(1-6*x_p(i)^2)*y_p(j)^2*(1-y_p(j)^2)+...
    2*(1-6*y_p(j)^2)*x_p(i)^2*(1-x_p(i)^2);
    uex(1,i + (j-1)*mx) = (x_p(i)^2-x_p(i)^4)*(y_p(j)^4-y_p(j)^2);
  end
  end
end

A = eye(mx*my);

for i = 1:mx
  for j= 1:my 
    if (i ~= 1 & i ~= mx & j ~= 1 & j ~= my)
      A(i + (j-1)*mx,i + (j-1)*mx) = 2*(1/hy^2 + 1/hx^2);
      A(i + (j-1)*mx,i + (j-1)*mx-1) = -1/hx^2;
      A(i + (j-1)*mx,i + (j-1)*mx+1) = -1/hx^2;
      A(i + (j-1)*mx,i + (j-1)*mx+mx) = -1/hy^2;
      A(i + (j-1)*mx,i + (j-1)*mx-mx) = -1/hy^2;
    end
  end 
end

u = A\f'


norm(u-uex,inf)
