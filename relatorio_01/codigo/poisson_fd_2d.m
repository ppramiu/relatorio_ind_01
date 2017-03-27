% Poisson equation -\nabla² u = f with dirichlet conditions u = 0
mx = 9;
my = 9;
hx = 1/(mx-1);
hy = 1/(my-1);
A = zeros(mx*my);
u = 
for i = 1:mx*my 
  A(i,i) = 2*(hx/hy + hy/hx);
end

for i=1:my-1
  for j=1:mx
    A(i+(j-1)*my,i+(j-1)*my+1) = -hy/hx;
    A(i+(j-1)*my+1,i+(j-1)*my) = -hy/hx;
  end
end
for i = 1:my
  for j = 1:mx-1
    A(i+(j-1)*my,i+j*my) = -hx/hy;
    A(i+j*my,i+(j-1)*my) = -hx/hy;
  end
end

spy(A)