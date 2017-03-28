% Poisson equation -\nabla² u = f with dirichlet conditions u = 0
close;
clear all;
mx = 4;
my = 3;
hx = 1/(mx-1);
hy = 1/(my-1);

x_points = linspace(0,1,(mx));
y_points = linspace(0,1,(my));

u = zeros(1,mx*my);

for i=1:mx
  for j=1:my
  if (i ~= 1 & i ~= mx & j ~= 1 & j ~= my)
    u(1,i + (j-1)*mx) = (x_points(i)^2-x_points(i)^4)*(y_points(j)^4-y_points(j)^2);
  end
  end
end

u'


A = eye(mx*my);

A = zeros(mx*my);
for i = 1:mx
  for j= 1:my 
    if (i ~= 1 & i ~= mx & j ~= 1 & j ~= my)
    A(i + (j-1)*mx,i + (j-1)*mx) = 2*(1/hy^2 + 1/hx^2);
    A(i + (j-1)*mx,i + (j-1)*mx-1) = -1/hx^2;
    A(i + (j-1)*mx,i + (j-1)*mx+1) = -1/hx^2;
    A(i + (j-1)*mx,i + (j-1)*mx+my+1) = -1/hy^2;
    A(i + (j-1)*mx,i + (j-1)*mx-(my+1)) = -1/hy^2;
    end
  end 
end

%for i=1:my-1
%  for j=1:mx
%  if (i ~= 1 & i ~= mx & j ~= 1 & j ~= my)
%    A(i+(j-1)*my,i+(j-1)*my+1) = -1/hx^2;
%    A(i+(j-1)*my+1,i+(j-1)*my) = -1/hx^2;
%   end
%  end
%end
%
%for i = 1:my
%  for j = 1:mx-1
%  if (i ~= 1 & i ~= mx & j ~= 1 & j ~= my)
%    A(i+(j-1)*my,i+j*my) = -1/hy^2;
%    A(i+j*my,i+(j-1)*my) = -1/hy^2
%    end
%  end
%end