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
    
protected:
    
    twitCurl twitterObj;
    std::string replyMsg;
    std::string tmpStr;
    
public:
    
    void setup(std::string userName, 
               std::string passWord, 
               std::string consumerKey, 
               std::string consumerSecret, 
               std::string tokenKey, 
               std::string tokenSecret)
    {
        
        twitterObj.setTwitterUsername( userName );
        twitterObj.setTwitterPassword( passWord );
        twitterObj.getOAuth().setConsumerKey(consumerKey);
        twitterObj.getOAuth().setConsumerSecret(consumerSecret);
        twitterObj.getOAuth().setOAuthTokenKey(tokenKey);
        twitterObj.getOAuth().setOAuthTokenSecret(tokenSecret);
        
    }
    
    void getFriendID(){
        
        /* Get friend ids */
        replyMsg = "";
        printf( "\nGetting friend ids\n" );
        tmpStr = "techcrunch";
        if( twitterObj.friendsIdsGet( tmpStr, false ) )
        {
            twitterObj.getLastWebResponse( replyMsg );
            printf( "\ntwitterClient:: twitCurl::friendsIdsGet web response:\n%s\n", replyMsg.c_str() );
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
            printf( "\ntwitterClient:: twitCurl::statusUpdate web response:\n%s\n", replyMsg.c_str() );
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
            printf( "\ntwitterClient:: twitCurl::search web response:\n%s\n", replyMsg.c_str() );
        }
        else
        {
            twitterObj.getLastCurlError( replyMsg );
            printf( "\ntwitterClient:: twitCurl::search error:\n%s\n", replyMsg.c_str() );
        }
        
    }
    
    void getUserTimeline(){
        
        /* Get user timeline */
        replyMsg = "";
        printf( "\nGetting user timeline\n" );
        if( twitterObj.timelineUserGet( false, false, 0 ) )
        {
            twitterObj.getLastWebResponse( replyMsg );
            printf( "\ntwitterClient:: twitCurl::timelineUserGet web response:\n%s\n", replyMsg.c_str() );
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
            printf( "\ntwitterClient:: twitCurl::statusDestroyById web response:\n%s\n", replyMsg.c_str() );
        }
        else
        {
            twitterObj.getLastCurlError( replyMsg );
            printf( "\ntwitterClient:: twitCurl::statusDestroyById error:\n%s\n", replyMsg.c_str() );
        }
    }
    
    void getPublicTimeline(){
        
        /* Get public timeline */
        replyMsg = "";
        printf( "\nGetting public timeline\n" );
        if( twitterObj.timelinePublicGet() )
        {
            twitterObj.getLastWebResponse( replyMsg );
            printf( "\ntwitterClient:: twitCurl::timelinePublicGet web response:\n%s\n", replyMsg.c_str() );
        }
        else
        {
            twitterObj.getLastCurlError( replyMsg );
            printf( "\ntwitterClient:: twitCurl::timelinePublicGet error:\n%s\n", replyMsg.c_str() );
        }
    }
    
    void getTrend(){
        
        /* Get trends */
        if( twitterObj.trendsDailyGet() )
        {
            twitterObj.getLastWebResponse( replyMsg );
            printf( "\ntwitterClient:: twitCurl::trendsDailyGet web response:\n%s\n", replyMsg.c_str() );
        }
        else
        {
            twitterObj.getLastCurlError( replyMsg );
            printf( "\ntwitterClient:: twitCurl::trendsDailyGet error:\n%s\n", replyMsg.c_str() );
        }
    }
    
};

#endif
