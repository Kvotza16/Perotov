function PERUTOV

fid = fopen('C:\Users\Bar\Documents\Visual Studio 2017\Projects\Petutov\project\1.txt', 'wt');

%get the image path from user
% ?????? (get value from user into variable and open the releavent image

% vars
c = [200 200 200 300 300 300 300 300 300 400 400 400 500];
r = [200 300 400 100 200 300 400 500 550 200 300 400 300];
numDots = length(c);

% good values of orange colour (check what range considered good)
orange_r =[195 255];
orange_g =[75 180];
orange_b =[0 35];

% values ranges of dark colours (check what range considered bad)
black_r =[100 200];
black_g =[100 200];
black_b =[100 200];

% reading the image pixels by coloumn and rows cordinates
RGB = imread('orange4.jpg');
pixels = impixel(RGB, c, r);
%%range = input(prompt,'s')

%
countBlacks = 0;
countColor = 0;

%
badCheckList = [0 0 0];
goodCheckList = [0 0 0];

for currPixel = 1:numDots
    for currPixelRGB = 1:numDots
		%check the red value of the pixel
		if (currPixelRGB == 1)
			if(pixels(currPixel,currPixelRGB) >= orange_r(1)) && (pixels(currPixel,currPixelRGB) <= orange_r(2))
				goodCheckList(currPixelRGB) = 1;
            end
			if(pixels(currPixel,currPixelRGB) >= black_r(1)) && (pixels(currPixel,currPixelRGB) <= black_r(2))
				badCheckList(currPixelRGB) = 1;
            end
        end
		%check the green value of the pixel
		if(currPixelRGB == 2)
			if(pixels(currPixel,currPixelRGB) >= orange_g(1) && pixels(currPixel,currPixelRGB) <= orange_g(2))
				goodCheckList(currPixelRGB) = 1;
            end
			if(pixels(currPixel,currPixelRGB) >= black_g(1) && pixels(currPixel,currPixelRGB) <= black_g(2))
				badCheckList(currPixelRGB) = 1;
            end
        end
		%check the blue value of the pixel
		if(currPixelRGB == 3)
			if(pixels(currPixel,currPixelRGB) >= orange_b(1)) && (pixels(currPixel,currPixelRGB) <= orange_b(2))
				goodCheckList(currPixelRGB) = 1;
            end
			if(pixels(currPixel,currPixelRGB) >= black_b(1)) && (pixels(currPixel,currPixelRGB) <= black_b(2))
				badCheckList(currPixelRGB) = 1;
            end
        end
    end
    % check if the pixel values correct to the right/bad color
    if(goodCheckList(1) == 1) && (goodCheckList(2) == 1) && (goodCheckList(3) == 1)
        countColor = countColor + 1;
    end
    if(badCheckList(1) == 1) && (badCheckList(2) == 1) && (badCheckList(3) == 1)
        countBlacks = countBlacks + 1;
    end
			
    % reset the checking values
    goodCheckList(1)=0;
    goodCheckList(2)=0;
    goodCheckList(3)=0;

    badCheckList(1)=0;
    badCheckList(2)=0;
    badCheckList(3)=0;
end

% caculate the precentage (for file write)
%if (countColor>countBlacks)
%    countColor = (countColor/numDots)*100;
%else
%    countBlacks = (countBlacks/numDots)*100;
%end

%print to file
%organize the structure of printing to file as the following:
%X - good color count
%Y - bad color count
fprintf(fid,'%d\n%d', countColor, countBlacks);
fclose(fid);