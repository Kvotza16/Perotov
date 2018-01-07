function MIX

fid = fopen('C:\Users\Bar\Documents\Visual Studio 2017\Projects\Petutov\project\report.txt', 'wt');

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
%fprintf(fid,'%d\n%d', countColor, countBlacks);

% second test

fid = fopen('C:\Users\Bar\Documents\Visual Studio 2017\Projects\Petutov\project\report.txt', 'wt');
 while(1);
     
prompt = 'Enter the name of file:  '; % name of file


fname = input(prompt,'s'); % name of input image
fruit = imread(fname);		% name of image in the program



width = 810;		%size of image ---> (resize)
images = {fruit};	

 dim = size(images{1}); %size images
 images{1} = imresize(images{1},[width*dim(1)/dim(2) width],'bicubic');

  % reading the image pixels by coloumn and rows cordinates
RGB = imread(fname);
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

 fruit = images{1};		%string of name

srgb2lab = makecform('srgb2lab');	%conver image
lab2srgb = makecform('lab2srgb');	%---//---

shadow_lab = applycform(fruit, srgb2lab); % convert to L*a*b*   %---//---

% the values of luminosity can span a range from 0 to 100; scale them
% to [0 1] range (appropriate for MATLAB(R) intensity images of class double) 
% before applying the three contrast enhancement techniques


max_luminosity = 1; 		%luminosity ---> ???????
L = shadow_lab(:,:,1)/max_luminosity;			

% replace the luminosity layer with the processed data and then convert
% the image back to the RGB colorspace

shadow_imadjust = shadow_lab; 
shadow_imadjust(:,:,1) = imadjust(L)*max_luminosity;
shadow_imadjust = applycform(shadow_imadjust, lab2srgb);

shadow_histeq = shadow_lab;
shadow_histeq(:,:,1) = histeq(L)*max_luminosity;
shadow_histeq = applycform(shadow_histeq, lab2srgb);

shadow_adapthisteq = shadow_lab;
shadow_adapthisteq(:,:,1) = adapthisteq(L)*max_luminosity;
shadow_adapthisteq = applycform(shadow_adapthisteq, lab2srgb);



% convert the image in gray-scale
% red green blue ---> convert to gray-scale image
I = rgb2gray(fruit);
fruit_imadjust = imadjust(I,[0.35 0.9],[0 1]);
m = 256; % number of sub gray collors

figure
% bar plot

[counts, binLocation] = imhist(I,m); %count bin location on axis (X side) and values of intensities (Y side)  
bar(binLocation,counts, 'FaceColor', [0 .5 .5], 'EdgeColor', [0 .5 .5]); % bar ---> ||||| (column histogram)
axis([0 256 0 20000]); 
colormap gray;
colorbar('SouthOutside'); 
% res1=0;
% res2=0;
% res3=0;
sum1 = 0;
for k=1:130
   sum1=sum1+counts(k); 
end
res1 = sum1/130;
sum2 = 0;
for k=131:190
   sum2=sum2+counts(k); 
end
res2=sum2/59;
sum3 = 2;
for k=191:255
   sum3=sum3+counts(k); 
end
res3=sum3/64;

% for k = 1:m % like ---> for(i=0;i<...;i++)
    fprintf (fid,'%10.2f\n%10.2f\n%10.2f\n%d\n%d', res1,res2,res3, countColor, countBlacks); % print results: counts ---> Y binLocation ---> X
    %fprintf(fid,'%d\n%d', countColor, countBlacks);
% end
%

% binLocation(k)--> after counts(k)%10.2f 
str = {'Original', 'Imadjust', 'Adapthisteq', 'Original-gray', 'Imadjust-gray'};
%Figures
figure, imshow(fruit);
title(str{1});

figure;
% input images into sheet square 
subplot(2,2,1),imshow(shadow_imadjust), title (str{2});
subplot(2,2,2),imshow(shadow_adapthisteq), title (str{3});
subplot(2,2,3), imshow(I), title (str{4});
subplot(2,2,4),imshow(fruit_imadjust), title (str{5});

% Report
prompt = 'If the fruit high quality or not? (yes/no):   ';% change
originality = input(prompt,'s');

% fprintf (fid, ' %6s %6s \n', fname, originality);



answer=input('Do you want to continue, Y/N [Y]/[N]:','s');
if (answer=='N' || answer=='n')
break
end    



 end
 fclose(fid);
end




