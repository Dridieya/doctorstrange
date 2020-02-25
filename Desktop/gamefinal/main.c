#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

void setrects(SDL_Rect* clip)
{

  clip[0].x=0;
  clip[0].y=0;
  clip[0].w=1280;
  clip[0].h=600;

  clip[1].x=1280;
  clip[1].y=0;
  clip[1].w=1280;
  clip[1].h=600; 
  
  clip[2].x=2650;
  clip[2].y=0;
  clip[2].w=1280;
  clip[2].h=600;

  clip[3].x=3840;
  clip[3].y=0;
  clip[3].w=1280;
  clip[3].h=600;

  clip[4].x=5120;
  clip[4].y=0;
  clip[4].w=1280;
  clip[4].h=600;

}
 
int main(int argc, char *argv[])
 
{
    SDL_Surface *Menu = NULL;
    SDL_Surface *ecran = NULL;
    SDL_Surface *Continue = NULL;
    SDL_Surface *Newgame = NULL;
    SDL_Surface *Option = NULL;
    SDL_Surface *Quit = NULL;
    SDL_Surface *test = NULL;
    SDL_Surface *exit = NULL;
    SDL_Surface *yes = NULL;
    SDL_Surface *no = NULL;
    SDL_Surface *text = NULL;
    TTF_Font *police = NULL;
 SDL_Color couleurNoire = {0, 0, 0};
    
  
   // const int FPS=30;
    int done=1;
    SDL_Event event,eventa;
    SDL_Rect positionMenu, positionContinue, positionNewgame, positionOption, positionQuit,pyes,pno,ptext,upsound,downsound,pwin,pfs;
    positionMenu.x=0;
    positionMenu.y=0;

    positionContinue.x=120;
    positionContinue.y=140;

    positionNewgame.x=120;
    positionNewgame.y=80;

    positionOption.x=120;
    positionOption.y=200;

    positionQuit.x=120;
    positionQuit.y=260;

    pyes.x=475;
    pyes.y=380;
    pno.x=740;
    pno.y=380;
    ptext.x=740;
    ptext.y=380;
    upsound.x=800;
    upsound.y=200;
    downsound.x=420;
    downsound.y=200;
    pwin.x=680;
    pwin.y=400;
    pfs.x=440;
    pfs.y=400;

    SDL_Init( SDL_INIT_EVERYTHING );
TTF_Init();
    ecran = SDL_SetVideoMode(1280,600,32,SDL_HWSURFACE);
    SDL_WM_SetCaption("MENU TEST", NULL);
    police = TTF_OpenFont("angelina.ttf", 40);
if (police==NULL)
{printf("erreur lice");
return 0;}
    text = TTF_RenderText_Blended(police, "credits : F4", couleurNoire);
    Menu = IMG_Load("back.png");
    SDL_BlitSurface(Menu,NULL, ecran, &positionMenu);
    Newgame = IMG_Load("botton/new.png");
    SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
    Continue = IMG_Load("botton/load.png");
    SDL_BlitSurface(Newgame, NULL, ecran, &positionNewgame);
    Option = IMG_Load("botton/set.png");
    SDL_BlitSurface(Option, NULL, ecran, &positionOption);
    Quit = IMG_Load("botton/exit.png");
    SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
    SDL_BlitSurface(text,NULL, ecran, &ptext);
    SDL_Flip( ecran );
    
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
    {
       printf("%s", Mix_GetError());
    }
    
    
    Mix_AllocateChannels(32);
    Mix_Chunk *over = NULL;
    over=Mix_LoadWAV("over.wav");
if (over==NULL)
{printf("erreur chunk");
return 0;}
    Mix_Music *musique; 
    musique = Mix_LoadMUS("music.mp3");
    Mix_PlayMusic(musique, -1);


while(done)
{

    
 while( SDL_PollEvent( &event ) )
    {
       switch(event.type)
            {
        case SDL_QUIT:
         done=0;
         break;
       case SDL_MOUSEMOTION:
        
      if (event.motion.x > positionContinue.x && event.motion.x < positionContinue.x+226 && event.motion.y > positionContinue.y && event.motion.y < positionContinue.y+47) {
         Mix_PlayChannel(-1,over,0);
         Continue = IMG_Load("botton/loadp.png");
         SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);}
     else 
     { Continue = IMG_Load("botton/load.png");
       SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);}

       if (event.motion.x > positionNewgame.x && event.motion.x < positionNewgame.x +226 && event.motion.y > positionNewgame.y && event.motion.y < positionNewgame.y +47) {
         Newgame = IMG_Load("botton/newp.png");
         SDL_BlitSurface(Newgame, NULL, ecran, &positionNewgame);
       Mix_PlayChannel(-1, over, 0 );}
     else 
     { Newgame = IMG_Load("botton/new.png");
       SDL_BlitSurface(Newgame, NULL, ecran, &positionNewgame);}

        if (event.motion.x > positionOption.x && event.motion.x < positionOption.x +226 && event.motion.y > positionOption.y && event.motion.y < positionOption.y +47) {
         Option = IMG_Load("botton/setp.png");
         SDL_BlitSurface(Option, NULL, ecran, &positionOption);
    Mix_PlayChannel( -1, over, 0 );}
     else 
     { Option = IMG_Load("botton/set.png");
       SDL_BlitSurface(Option, NULL, ecran, &positionOption);}

        if (event.motion.x > positionQuit.x && event.motion.x < positionQuit.x +226 && event.motion.y > positionQuit.y && event.motion.y < positionQuit.y +47) {
         Quit = IMG_Load("botton/exitp.png");
         SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);}
     else 
     { Quit = IMG_Load("botton/exit.png");
       SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
    Mix_PlayChannel( -1, over, 0 );}

SDL_Flip( ecran );break; //
     case SDL_MOUSEBUTTONDOWN:

    if( event.button.button == SDL_BUTTON_LEFT )

{if (event.motion.x > positionNewgame.x && event.motion.x < positionNewgame.x +226 && event.motion.y > positionNewgame.y && event.motion.y < positionNewgame.y +47) {
         Menu = IMG_Load("bot/bg.png");
         SDL_BlitSurface(Menu, NULL, ecran, NULL);
    }

if (event.motion.x > positionContinue.x && event.motion.x < positionContinue.x+226 && event.motion.y > positionContinue.y && event.motion.y < positionContinue.y+47) {
         Menu = IMG_Load("bot/bg.png");
         SDL_BlitSurface(Menu, NULL, ecran, NULL);}

if (event.motion.x > positionOption.x && event.motion.x < positionOption.x +226 && event.motion.y > positionOption.y && event.motion.y < positionOption.y +47) {
         Menu = IMG_Load("bot/settings.png");
         SDL_BlitSurface(Menu, NULL, ecran, NULL);;
         yes = IMG_Load("bot/+.png");
         SDL_BlitSurface(yes, NULL, ecran, &upsound);
         no = IMG_Load("bot/-.png");
         SDL_BlitSurface(no, NULL, ecran, &downsound);
         yes = IMG_Load("bot/w.png");
         SDL_BlitSurface(yes, NULL, ecran, &pwin);
         no = IMG_Load("bot/fs.png");
         SDL_BlitSurface(no, NULL, ecran, &pfs);
}

if (event.motion.x > positionQuit.x && event.motion.x < positionQuit.x +226 && event.motion.y > positionQuit.y && event.motion.y < positionQuit.y +47){
         exit = IMG_Load("exitcf/exitcf.png");
         SDL_BlitSurface(exit, NULL, ecran, &positionMenu);
         yes = IMG_Load("botton/yes.png");
         SDL_BlitSurface(yes, NULL, ecran, &pyes);
         no = IMG_Load("botton/no.png");
         SDL_BlitSurface(no, NULL, ecran, &pno);
  
    while( SDL_PollEvent( &eventa ) )
      {
        switch(event.type)
            {
          case SDL_MOUSEMOTION:
         if (event.motion.x > pyes.x && event.motion.x < pyes.x +82 && event.motion.y > pyes.y && event.motion.y < pyes.y +41 &&(event.button.button == SDL_BUTTON_LEFT))
         {yes = IMG_Load("exitcf/yesp.png");
         SDL_BlitSurface(yes, NULL, ecran, &pyes);}
else 
{yes = IMG_Load("botton/yes.png");
         SDL_BlitSurface(yes, NULL, ecran, &pyes);}

         if (event.motion.x > pno.x && event.motion.x < pno.x +82 && event.motion.y > pno.y && event.motion.y < pno.y +41)
         {no = IMG_Load("exitcf/nop.png");
         SDL_BlitSurface(no, NULL, ecran, &pno);}
else     {no = IMG_Load("botton/no.png");
         SDL_BlitSurface(no, NULL, ecran, &pno);}break;}}
}
if (event.motion.x > pyes.x && event.motion.x < pyes.x +82 && event.motion.y > pyes.y && event.motion.y < pyes.y +41)
  done=0;
if (event.motion.x > pno.x && event.motion.x < pno.x +82 && event.motion.y > pno.y && event.motion.y < pno.y +41)
{
 Menu = IMG_Load("back.png");
    SDL_BlitSurface(Menu,NULL, ecran, &positionMenu);
    Continue = IMG_Load("botton/load.png");
    SDL_BlitSurface(Continue, NULL, ecran, &positionContinue);
    Newgame = IMG_Load("botton/new.png");
    SDL_BlitSurface(Newgame, NULL, ecran, &positionNewgame);
    Option = IMG_Load("botton/set.png");
    SDL_BlitSurface(Option, NULL, ecran, &positionOption);
    Quit = IMG_Load("botton/exit.png");
    SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
    SDL_Flip( ecran );}     
   }
    break;
     case SDL_KEYDOWN:
       switch(event.key.keysym.sym)
                {
                   case SDLK_j:
         {test = IMG_Load("bot/bg.png");
         SDL_BlitSurface(test, NULL, ecran, NULL);}break;
                  case SDLK_ESCAPE:
       { exit = IMG_Load("exitcf/exitcf.png");
         SDL_BlitSurface(exit, NULL, ecran, &positionMenu);
         yes = IMG_Load("botton/yes.png");
         SDL_BlitSurface(yes, NULL, ecran, &pyes);
         no = IMG_Load("botton/no.png");
         SDL_BlitSurface(no, NULL, ecran, &pno);
}break;
             case SDLK_m:
  if (Mix_VolumeMusic(0))
    Mix_VolumeMusic(100);
if (Mix_VolumeMusic(100))
Mix_VolumeMusic(0);

           // case SDLK_UP:
             
 
 
break;}
break;}
   }
}
    Mix_FreeChunk(over);
TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(Menu);
    SDL_FreeSurface(Continue);
    SDL_FreeSurface(Newgame); 
    SDL_FreeSurface(Option);
    SDL_FreeSurface(Quit);
    SDL_FreeSurface(test);
    SDL_FreeSurface(exit);
    Mix_FreeMusic(musique); 
    Mix_CloseAudio(); 
    SDL_Quit();
    return 0;
}


