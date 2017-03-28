% Poisson equation -\nabla² u = f with dirichlet conditions u = 0
clear all;
mx = 4;
my = 3;
hx = 1/(mx-1);
hy = 1/(my-1);

x_points = linspace(0,1,(mx));
y_points = linspace(0,1,(my));

for i=1:mx
  for j=1:my
    u(i,j) =  (x_points(i)^2-x_points(i)^4)*(y_points(j)^4-y_points(j)^2);
  end
end

u=reshape(u,1,[])

A = zeros(mx*my);
for i = 1:mx*my 
  A(i,i) = 2*(1/hy^2 + 1/hx^2);
end

for i=1:my-1
  for j=1:mx
    A(i+(j-1)*my,i+(j-1)*my+1) = -1/hx^2;
    A(i+(j-1)*my+1,i+(j-1)*my) = -1/hx^2;
  end
end
for i = 1:my
  for j = 1:mx-1
    A(i+(j-1)*my,i+j*my) = -1/hy^2;
    A(i+j*my,i+(j-1)*my) = -1/hy^2;
  end
end

b = A*u';
A\b

spy(A)