//
//  ofxTwitcurl.h
//  emptyExample
//
//  Created by 정운 김 on 4/23/12.
//  Copyright (c) 2012 pinkroad.co.cc. All rights reserved.
//

#ifndef emptyExample_ofxTwitcurl_h
#define emptyExample_ofxTwitcurl_h

#include "twitcurl.h"

class ofxTwitcurl{
    
private:
    
    std::string replyMsg;
    
protected:
    
    twitCurl twitterObj;
    
public:
    
    void setup(std::string userName, 
               std::string passWord,
               std::string consumerKey, 
               std::string consumerSecret
               )
    {
        setUser(userName, passWord);
        setConsumer(consumerKey, consumerSecret);
        requestToken();
    }
    
    void setUser(std::string userName, std::string passWord)
    {
        
        twitterObj.setTwitterUsername( userName );
        twitterObj.setTwitterPassword( passWord );
        
    }
    
    void setConsumer(std::string consumerKey, std::string consumerSecret)
    {
        
        twitterObj.getOAuth().setConsumerKey(consumerKey);
        twitterObj.getOAuth().setConsumerSecret(consumerSecret);
        
    }
    
    void requestToken(){
        
        std::string authUrl;

        twitterObj.oAuthRequestToken(authUrl);
        twitterObj.oAuthHandlePIN( authUrl );

        twitterObj.oAuthAccessToken();

    }
    
    void setToken(std::string tokenKey, std::string tokenSecret)
    {
        
        twitterObj.getOAuth().setOAuthTokenKey(tokenKey);
        twitterObj.getOAuth().setOAuthTokenSecret(tokenSecret);
        
    }
    
    void getFriendID(std::string userInfo){
        
        /* Get friend ids */
        replyMsg = "";
        if( twitterObj.friendsIdsGet( userInfo, false ) )
        {
            twitterObj.getLastWebResponse( replyMsg );
            //printf( "\ntwitterClient:: twitCurl::friendsIdsGet web response:\n%s\n", replyMsg.c_str() );
        }
        else
        {
            twitterObj.getLastCurlError( replyMsg );
            printf( "\ntwitterClient:: twitCurl::friendsIdsGet error:\n%s\n", replyMsg.c_str() );
        }
        
    }
    
    void postNewStatus(std::string newStatus){
        
        /* Post a new status message */
        
        replyMsg = "";
        if( twitterObj.statusUpdate( newStatus ) )
        {
            twitterObj.getLastWebResponse( replyMsg );
            //printf( "\ntwitterClient:: twitCurl::statusUpdate web response:\n%s\n", replyMsg.c_str() );
        }
        else
        {
            twitterObj.getLastCurlError( replyMsg );
            printf( "\ntwitterClient:: twitCurl::statusUpdate error:\n%s\n", replyMsg.c_str() );
        }
        
    }
    
    void searchString(std::string searchWord){
        
        //you can use ofxtwitter also
        /* Search a string */
        twitterObj.setTwitterApiType( twitCurlTypes::eTwitCurlApiFormatJson );
        
        if( twitterObj.search( searchWord ) )
        {
            twitterObj.getLastWebResponse( replyMsg );
            //printf( "\ntwitterClient:: twitCurl::search web response:\n%s\n", replyMsg.c_str() );
        }
        else
        {
            twitterObj.getLastCurlError( replyMsg );
            printf( "\ntwitterClient:: twitCurl::search error:\n%s\n", replyMsg.c_str() );
        }
        
    }
    
    void getPublicTimeline(){
        
        /* Get public timeline */
        replyMsg = "";
        printf( "\nGetting public timeline\n" );
        if( twitterObj.timelinePublicGet() )
        {
            twitterObj.getLastWebResponse( replyMsg );
            //printf( "\ntwitterClient:: twitCurl::timelinePublicGet web response:\n%s\n", replyMsg.c_str() );
        }
        else
        {
            twitterObj.getLastCurlError( replyMsg );
            printf( "\ntwitterClient:: twitCurl::timelinePublicGet error:\n%s\n", replyMsg.c_str() );
        }
    }
    
    void getUserTimeline(){
        
        /* Get user timeline */
        replyMsg = "";
        printf( "\nGetting user timeline\n" );
        if( twitterObj.timelineUserGet( false, false, 0 ) )
        {
            twitterObj.getLastWebResponse( replyMsg );
            //printf( "\ntwitterClient:: twitCurl::timelineUserGet web response:\n%s\n", replyMsg.c_str() );
        }
        else
        {
            twitterObj.getLastCurlError( replyMsg );
            printf( "\ntwitterClient:: twitCurl::timelineUserGet error:\n%s\n", replyMsg.c_str() );
        }
        
    }
    
    void destroyStatusMessage(std::string statusMsg){
        
        /* Destroy a status message */
        replyMsg = "";
        if( twitterObj.statusDestroyById( statusMsg ) )
        {
            twitterObj.getLastWebResponse( replyMsg );
            //printf( "\ntwitterClient:: twitCurl::statusDestroyById web response:\n%s\n", replyMsg.c_str() );
        }
        else
        {
            twitterObj.getLastCurlError( replyMsg );
            printf( "\ntwitterClient:: twitCurl::statusDestroyById error:\n%s\n", replyMsg.c_str() );
        }
    }
    
    void getTrend(){
        
        /* Get trends */
        if( twitterObj.trendsDailyGet() )
        {
            twitterObj.getLastWebResponse( replyMsg );
            //printf( "\ntwitterClient:: twitCurl::trendsDailyGet web response:\n%s\n", replyMsg.c_str() );
        }
        else
        {
            twitterObj.getLastCurlError( replyMsg );
            printf( "\ntwitterClient:: twitCurl::trendsDailyGet error:\n%s\n", replyMsg.c_str() );
        }
    }
    
    std::string getData() const {
        
        return replyMsg;
    }
    
};

#endif
