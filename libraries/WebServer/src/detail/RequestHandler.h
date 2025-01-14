#pragma once

#include <vector>
#include <assert.h>

class RequestHandler {
public:
    virtual ~RequestHandler() { }
    virtual bool canHandle(HTTPMethod method, String uri) {
        (void) method;
        (void) uri;
        return false;
    }
    virtual bool canUpload(String uri) {
        (void) uri;
        return false;
    }
    virtual bool handle(HTTPServer& server, HTTPMethod requestMethod, String requestUri) {
        (void) server;
        (void) requestMethod;
        (void) requestUri;
        return false;
    }
    virtual void upload(HTTPServer& server, String requestUri, HTTPUpload& upload) {
        (void) server;
        (void) requestUri;
        (void) upload;
    }

    RequestHandler* next() {
        return _next;
    }
    void next(RequestHandler* r) {
        _next = r;
    }

private:
    RequestHandler* _next = nullptr;

protected:
    std::vector<String> pathArgs;

public:
    const String& pathArg(unsigned int i) {
        assert(i < pathArgs.size());
        return pathArgs[i];
    }
};
