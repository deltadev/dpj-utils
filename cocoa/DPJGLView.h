#import <Cocoa/Cocoa.h>
#import <QuartzCore/CVDisplayLink.h>

#import <GLKit/GLKit.h>

#include <memory>

#include "render_context.hh"



@class DPJGLView;

@protocol DPJGLDelegate

@required
- (void)viewDidInitGL;
- (void)glLayoutChanged:(DPJGLView*)view;
- (void)draw;
@end

@interface DPJGLView : NSOpenGLView
{
#ifdef __cplusplus
  @public
    std::unique_ptr<dpj::gl::render_context> render_context;
#endif
}

@property (assign, nonatomic) CVDisplayLinkRef displayLink;

- (void)reshapeFrustumFromNear:(float)near far:(float)far fov:(float)fov;

- (id)initWithFrame:(NSRect)frameRect;

@property (nonatomic, weak) id<DPJGLDelegate> delegate;
@end

