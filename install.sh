NAME=sdl-helper


if [ -d $USER_INCLUDE/$NAME ]
then
    rm -r $USER_INCLUDE/$NAME  
fi
mkdir $USER_INCLUDE/$NAME

if [ -e $USER_LIB/$NAME.a ]
then
    rm $USER_LIB/$NAME.a
fi


cp include/* $USER_INCLUDE/$NAME
cp lib/$NAME.a $USER_LIB/$NAME.a