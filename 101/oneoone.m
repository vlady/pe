function [ans] = oneoone()
two()
val = zeros(1,10);
for i = 1:10
  val(1,i) = f([1,-1,1,-1,1,-1,1,-1,1,-1,1],i);
end
ssum = 0;
for i = 1:10
  x = [];
  y = val(1,1:i);
  for j = 1:i
    x = [x, j];
  end
  bop = f(polyfit(x, y, i-1), i+1)
  ssum = ssum + bop;
  sprintf("%d", bop)
end
 sprintf("%d", ssum)
ans = val;
end
function [ans] = f(g, n)
  m = size(g,2);
  ans = 0;
  i = 1;
  while m > 0
    r = n**(m-1);
    ans = ans + g(1,i)*r;
    m = m - 1;
    i = i + 1;
  end
end
