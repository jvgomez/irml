  


<!DOCTYPE html>
<html>
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# githubog: http://ogp.me/ns/fb/githubog#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>irml/pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp at master · jvgomez/irml</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="shortcut icon" href="/favicon.ico" type="image/x-icon" />
    <link rel="apple-touch-icon-precomposed" sizes="57x57" href="apple-touch-icon-114.png" />
    <link rel="apple-touch-icon-precomposed" sizes="114x114" href="apple-touch-icon-114.png" />
    <link rel="apple-touch-icon-precomposed" sizes="72x72" href="apple-touch-icon-144.png" />
    <link rel="apple-touch-icon-precomposed" sizes="144x144" href="apple-touch-icon-144.png" />

    
    

    <meta content="authenticity_token" name="csrf-param" />
<meta content="yx/b3wzTueYNDE5aWjMPcZB1wj7Dc38cQ9OTUg/O4F4=" name="csrf-token" />

    <link href="https://a248.e.akamai.net/assets.github.com/assets/github-93e28295e9de4310090c4fe2ed0851ddde77ddfa.css" media="screen" rel="stylesheet" type="text/css" />
    <link href="https://a248.e.akamai.net/assets.github.com/assets/github2-2ef148486376675ad2c42348f04cbb83dcc5a10e.css" media="screen" rel="stylesheet" type="text/css" />
    
    


    <script src="https://a248.e.akamai.net/assets.github.com/assets/frameworks-c86655d74d3a1c4761cfc641f9400895db04e2f8.js" type="text/javascript"></script>
    
    <script defer="defer" src="https://a248.e.akamai.net/assets.github.com/assets/github-9ba225d9e6c45ea1219dfb0a4bf829b03d47c271.js" type="text/javascript"></script>
    
    

      <link rel='permalink' href='/jvgomez/irml/blob/b331eeb6b32d46dfb53fd6c2c2f55d5e85c6f436/pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp'>
    <meta property="og:title" content="irml"/>
    <meta property="og:type" content="githubog:gitrepository"/>
    <meta property="og:url" content="https://github.com/jvgomez/irml"/>
    <meta property="og:image" content="https://a248.e.akamai.net/assets.github.com/images/gravatars/gravatar-140.png?1329275856"/>
    <meta property="og:site_name" content="GitHub"/>
    <meta property="og:description" content="IRML Project Repository. Contribute to irml development by creating an account on GitHub."/>

    <meta name="description" content="IRML Project Repository. Contribute to irml development by creating an account on GitHub." />

  <link href="https://github.com/jvgomez/irml/commits/master.atom" rel="alternate" title="Recent Commits to irml:master" type="application/atom+xml" />

  </head>


  <body class="logged_in page-blob linux vis-public env-production " data-blob-contribs-enabled="yes">
    <div id="wrapper">

    
    
    

      <div id="header" class="true clearfix">
        <div class="container clearfix">
          <a class="site-logo" href="https://github.com/">
            <!--[if IE]>
            <img alt="GitHub" class="github-logo" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7.png?1323882717" />
            <img alt="GitHub" class="github-logo-hover" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7-hover.png?1324325359" />
            <![endif]-->
            <img alt="GitHub" class="github-logo-4x" height="30" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7@4x.png?1337118068" />
            <img alt="GitHub" class="github-logo-4x-hover" height="30" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7@4x-hover.png?1337118068" />
          </a>


              
    <div class="topsearch  ">
        <form accept-charset="UTF-8" action="/search" id="top_search_form" method="get">
  <a href="/search" class="advanced-search tooltipped downwards" title="Advanced Search"><span class="mini-icon mini-icon-advanced-search"></span></a>
  <div class="search placeholder-field js-placeholder-field">
    <input type="text" class="search my_repos_autocompleter" id="global-search-field" name="q" results="5" spellcheck="false" autocomplete="off" data-autocomplete="my-repos-autocomplete" placeholder="Search&hellip;" data-hotkey="s" />
    <div id="my-repos-autocomplete" class="autocomplete-results">
      <ul class="js-navigation-container"></ul>
    </div>
    <input type="submit" value="Search" class="button">
    <span class="mini-icon mini-icon-search-input"></span>
  </div>
  <input type="hidden" name="type" value="Everything" />
  <input type="hidden" name="repo" value="" />
  <input type="hidden" name="langOverride" value="" />
  <input type="hidden" name="start_value" value="1" />
</form>

      <ul class="top-nav">
          <li class="explore"><a href="https://github.com/explore">Explore</a></li>
          <li><a href="https://gist.github.com">Gist</a></li>
          <li><a href="/blog">Blog</a></li>
        <li><a href="http://help.github.com">Help</a></li>
      </ul>
    </div>


            


  <div id="userbox">
    <div id="user">
      <a href="https://github.com/jvgomez"><img height="20" src="https://secure.gravatar.com/avatar/d68ee266ecb4a9b8908865bed767622e?s=140&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-140.png" width="20" /></a>
      <a href="https://github.com/jvgomez" class="name">jvgomez</a>
    </div>
    <ul id="user-links">
      <li>
        <a href="/new" id="new_repo" class="tooltipped downwards" title="Create a New Repo"><span class="mini-icon mini-icon-create"></span></a>
      </li>
      <li>
        <a href="/inbox/notifications" id="notifications" class="tooltipped downwards" title="Notifications">
          <span class="mini-icon mini-icon-notifications"></span>
        </a>
      </li>
      <li>
        <a href="/settings/profile" id="settings"
          class="tooltipped downwards"
          title="Account Settings ">
          <span class="mini-icon mini-icon-account-settings"></span>
        </a>
      </li>
      <li>
          <a href="/logout" data-method="post" id="logout" class="tooltipped downwards" title="Sign Out">
            <span class="mini-icon mini-icon-logout"></span>
          </a>
      </li>
    </ul>
  </div>



          
        </div>
      </div>

      

            <div class="site hfeed" itemscope itemtype="http://schema.org/WebPage">
      <div class="container hentry">
        <div class="pagehead repohead instapaper_ignore readability-menu">
        <div class="title-actions-bar">
          



              <ul class="pagehead-actions">

          <li class="for-owner"><a href="/jvgomez/irml/admin" class="minibutton btn-admin ">Admin</a></li>

          <li class="nspr">
            <a href="/jvgomez/irml/pull/new/master" class="minibutton btn-pull-request ">Pull Request</a>
          </li>


          <li class="js-toggler-container js-social-container watch-button-container on">
            <span class="watch-button"><a href="/jvgomez/irml/toggle_watch" class="minibutton btn-watch js-toggler-target lighter" data-remote="true" data-method="post" rel="nofollow">Watch</a><a class="social-count js-social-count" href="/jvgomez/irml/watchers">1</a></span>
            <span class="unwatch-button"><a href="/jvgomez/irml/toggle_watch" class="minibutton btn-unwatch js-toggler-target lighter" data-remote="true" data-method="post" rel="nofollow">Unwatch</a><a class="social-count js-social-count" href="/jvgomez/irml/watchers">1</a></span>
          </li>

              <li><a href="/jvgomez/irml/fork" class="minibutton btn-fork js-toggler-target fork-button lighter" rel="nofollow" data-method="post">Fork</a><a href="/jvgomez/irml/network" class="social-count">1</a>
              </li>


    </ul>

          <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
            <span class="repo-label"><span>public</span></span>
            <span class="mega-icon mega-icon-public-repo"></span>
            <span class="author vcard">
<a href="/jvgomez" class="url fn" itemprop="url" rel="author">              <span itemprop="title">jvgomez</span>
              </a></span> /
            <strong><a href="/jvgomez/irml" class="js-current-repository">irml</a></strong>
          </h1>
        </div>

          

  <ul class="tabs">
    <li><a href="/jvgomez/irml" class="selected" highlight="repo_sourcerepo_downloadsrepo_commitsrepo_tagsrepo_branches">Code</a></li>
    <li><a href="/jvgomez/irml/network" highlight="repo_network">Network</a>
    <li><a href="/jvgomez/irml/pulls" highlight="repo_pulls">Pull Requests <span class='counter'>0</span></a></li>

      <li><a href="/jvgomez/irml/issues" highlight="repo_issues">Issues <span class='counter'>0</span></a></li>

      <li><a href="/jvgomez/irml/wiki" highlight="repo_wiki">Wiki</a></li>

    <li><a href="/jvgomez/irml/graphs" highlight="repo_graphsrepo_contributors">Graphs</a></li>

  </ul>
 
<div class="frame frame-center tree-finder" style="display:none"
      data-tree-list-url="/jvgomez/irml/tree-list/b331eeb6b32d46dfb53fd6c2c2f55d5e85c6f436"
      data-blob-url-prefix="/jvgomez/irml/blob/b331eeb6b32d46dfb53fd6c2c2f55d5e85c6f436"
    >

  <div class="breadcrumb">
    <span class="bold"><a href="/jvgomez/irml">irml</a></span> /
    <input class="tree-finder-input js-navigation-enable" type="text" name="query" autocomplete="off" spellcheck="false">
  </div>

    <div class="octotip">
      <p>
        <a href="/jvgomez/irml/dismiss-tree-finder-help" class="dismiss js-dismiss-tree-list-help" title="Hide this notice forever" rel="nofollow">Dismiss</a>
        <span class="bold">Octotip:</span> You've activated the <em>file finder</em>
        by pressing <span class="kbd">t</span> Start typing to filter the
        file list. Use <span class="kbd badmono">↑</span> and
        <span class="kbd badmono">↓</span> to navigate,
        <span class="kbd">enter</span> to view files.
      </p>
    </div>

  <table class="tree-browser" cellpadding="0" cellspacing="0">
    <tr class="js-header"><th>&nbsp;</th><th>name</th></tr>
    <tr class="js-no-results no-results" style="display: none">
      <th colspan="2">No matching files</th>
    </tr>
    <tbody class="js-results-list js-navigation-container">
    </tbody>
  </table>
</div>

<div id="jump-to-line" style="display:none">
  <h2>Jump to Line</h2>
  <form accept-charset="UTF-8">
    <input class="textfield" type="text">
    <div class="full-button">
      <button type="submit" class="classy">
        Go
      </button>
    </div>
  </form>
</div>


<div class="subnav-bar">

  <ul class="actions subnav">
    <li><a href="/jvgomez/irml/tags" class="blank" highlight="repo_tags">Tags <span class="counter">0</span></a></li>
    <li><a href="/jvgomez/irml/downloads" class="blank downloads-blank" highlight="repo_downloads">Downloads <span class="counter">0</span></a></li>
    
  </ul>

  <ul class="scope">
    <li class="switcher">

      <div class="context-menu-container js-menu-container js-context-menu">
        <a href="#"
           class="minibutton bigger switcher js-menu-target js-commitish-button btn-branch repo-tree"
           data-hotkey="w"
           data-master-branch="master"
           data-ref="master">
           <span><i>branch:</i> master</span>
        </a>

        <div class="context-pane commitish-context js-menu-content">
          <a href="javascript:;" class="close js-menu-close"><span class="mini-icon mini-icon-remove-close"></span></a>
          <div class="context-title">Switch branches/tags</div>
          <div class="context-body pane-selector commitish-selector js-navigation-container">
            <div class="filterbar">
              <input type="text" id="context-commitish-filter-field" class="js-navigation-enable" placeholder="Filter branches/tags" data-filterable />

              <ul class="tabs">
                <li><a href="#" data-filter="branches" class="selected">Branches</a></li>
                <li><a href="#" data-filter="tags">Tags</a></li>
              </ul>
            </div>

            <div class="js-filter-tab js-filter-branches" data-filterable-for="context-commitish-filter-field" data-filterable-type=substring>
              <div class="no-results js-not-filterable">Nothing to show</div>
                <div class="commitish-item branch-commitish selector-item js-navigation-item js-navigation-target selected">
                  <span class="mini-icon mini-icon-confirm"></span>
                  <h4>
                      <a href="/jvgomez/irml/blob/master/pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp" class="js-navigation-open" data-name="master" rel="nofollow">master</a>
                  </h4>
                </div>
            </div>

            <div class="js-filter-tab js-filter-tags" style="display:none" data-filterable-for="context-commitish-filter-field" data-filterable-type=substring>
              <div class="no-results js-not-filterable">Nothing to show</div>
            </div>
          </div>
        </div><!-- /.commitish-context-context -->
      </div>

    </li>
  </ul>

  <ul class="subnav with-scope">

    <li><a href="/jvgomez/irml" class="selected" highlight="repo_source">Files</a></li>
    <li><a href="/jvgomez/irml/commits/master" highlight="repo_commits">Commits</a></li>
    <li><a href="/jvgomez/irml/branches" class="" highlight="repo_branches" rel="nofollow">Branches <span class="counter">1</span></a></li>
  </ul>

</div>

  
  
  


          

        </div><!-- /.repohead -->

        <div id="js-repo-pjax-container" data-pjax-container>
          





<!-- block_view_fragment_key: views10/v8/blob:v21:9f2c97a9d56ce7d38078bf0614ec0964 -->
  <div id="slider">

    <div class="breadcrumb" data-path="pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp/">
      <b itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/jvgomez/irml/tree/b331eeb6b32d46dfb53fd6c2c2f55d5e85c6f436" class="js-rewrite-sha" itemprop="url"><span itemprop="title">irml</span></a></b> / <span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/jvgomez/irml/tree/b331eeb6b32d46dfb53fd6c2c2f55d5e85c6f436/pointclouds" class="js-rewrite-sha" itemscope="url"><span itemprop="title">pointclouds</span></a></span> / <span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/jvgomez/irml/tree/b331eeb6b32d46dfb53fd6c2c2f55d5e85c6f436/pointclouds/processing" class="js-rewrite-sha" itemscope="url"><span itemprop="title">processing</span></a></span> / <span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/jvgomez/irml/tree/b331eeb6b32d46dfb53fd6c2c2f55d5e85c6f436/pointclouds/processing/vfh_recognition" class="js-rewrite-sha" itemscope="url"><span itemprop="title">vfh_recognition</span></a></span> / <span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/jvgomez/irml/tree/b331eeb6b32d46dfb53fd6c2c2f55d5e85c6f436/pointclouds/processing/vfh_recognition/flanntree" class="js-rewrite-sha" itemscope="url"><span itemprop="title">flanntree</span></a></span> / <strong class="final-path">build_tree.cpp</strong> <span class="js-clippy mini-icon mini-icon-clippy " data-clipboard-text="pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp" data-copied-hint="copied!" data-copy-hint="copy to clipboard"></span>
    </div>


      <div class="commit file-history-tease" data-path="pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp/">
        <img class="main-avatar" height="24" src="https://secure.gravatar.com/avatar/d68ee266ecb4a9b8908865bed767622e?s=140&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-140.png" width="24" />
        <span class="author"><a href="/jvgomez">jvgomez</a></span>
        <time class="js-relative-date" datetime="2012-07-10T02:45:02-07:00" title="2012-07-10 02:45:02">July 10, 2012</time>
        <div class="commit-title">
            <a href="/jvgomez/irml/commit/67185164c318c7ab5ca9a0f0876b2186ec6267e7" class="message">PCL vfh recognition</a>
        </div>

        <div class="participation">
          <p class="quickstat"><a href="#blob_contributors_box" rel="facebox"><strong>1</strong> contributor</a></p>
          
        </div>
        <div id="blob_contributors_box" style="display:none">
          <h2>Users on GitHub who have contributed to this file</h2>
          <ul class="facebox-user-list">
            <li>
              <img height="24" src="https://secure.gravatar.com/avatar/d68ee266ecb4a9b8908865bed767622e?s=140&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-140.png" width="24" />
              <a href="/jvgomez">jvgomez</a>
            </li>
          </ul>
        </div>
      </div>

    <div class="frames">
      <div class="frame frame-center" data-path="pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp/" data-permalink-url="/jvgomez/irml/blob/b331eeb6b32d46dfb53fd6c2c2f55d5e85c6f436/pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp" data-title="irml/pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp at master · jvgomez/irml · GitHub" data-type="blob">

        <div id="files" class="bubble">
          <div class="file">
            <div class="meta">
              <div class="info">
                <span class="icon"><b class="mini-icon mini-icon-text-file"></b></span>
                <span class="mode" title="File Mode">100644</span>
                  <span>139 lines (120 sloc)</span>
                <span>4.612 kb</span>
              </div>
              <ul class="button-group actions">
                  <li>
                    <a class="grouped-button file-edit-link minibutton bigger lighter js-rewrite-sha" href="/jvgomez/irml/edit/b331eeb6b32d46dfb53fd6c2c2f55d5e85c6f436/pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp" data-method="post" rel="nofollow" data-hotkey="e">Edit this file</a>
                  </li>

                <li>
                  <a href="/jvgomez/irml/raw/master/pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp" class="minibutton btn-raw grouped-button bigger lighter" id="raw-url">Raw</a>
                </li>
                  <li>
                    <a href="/jvgomez/irml/blame/master/pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp" class="minibutton btn-blame grouped-button bigger lighter">Blame</a>
                  </li>
                <li>
                  <a href="/jvgomez/irml/commits/master/pointclouds/processing/vfh_recognition/flanntree/build_tree.cpp" class="minibutton btn-history grouped-button bigger lighter" rel="nofollow">History</a>
                </li>
              </ul>
            </div>
              <div class="data type-c">
      <table cellpadding="0" cellspacing="0" class="lines">
        <tr>
          <td>
            <pre class="line_numbers"><span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>
<span id="L74" rel="#L74">74</span>
<span id="L75" rel="#L75">75</span>
<span id="L76" rel="#L76">76</span>
<span id="L77" rel="#L77">77</span>
<span id="L78" rel="#L78">78</span>
<span id="L79" rel="#L79">79</span>
<span id="L80" rel="#L80">80</span>
<span id="L81" rel="#L81">81</span>
<span id="L82" rel="#L82">82</span>
<span id="L83" rel="#L83">83</span>
<span id="L84" rel="#L84">84</span>
<span id="L85" rel="#L85">85</span>
<span id="L86" rel="#L86">86</span>
<span id="L87" rel="#L87">87</span>
<span id="L88" rel="#L88">88</span>
<span id="L89" rel="#L89">89</span>
<span id="L90" rel="#L90">90</span>
<span id="L91" rel="#L91">91</span>
<span id="L92" rel="#L92">92</span>
<span id="L93" rel="#L93">93</span>
<span id="L94" rel="#L94">94</span>
<span id="L95" rel="#L95">95</span>
<span id="L96" rel="#L96">96</span>
<span id="L97" rel="#L97">97</span>
<span id="L98" rel="#L98">98</span>
<span id="L99" rel="#L99">99</span>
<span id="L100" rel="#L100">100</span>
<span id="L101" rel="#L101">101</span>
<span id="L102" rel="#L102">102</span>
<span id="L103" rel="#L103">103</span>
<span id="L104" rel="#L104">104</span>
<span id="L105" rel="#L105">105</span>
<span id="L106" rel="#L106">106</span>
<span id="L107" rel="#L107">107</span>
<span id="L108" rel="#L108">108</span>
<span id="L109" rel="#L109">109</span>
<span id="L110" rel="#L110">110</span>
<span id="L111" rel="#L111">111</span>
<span id="L112" rel="#L112">112</span>
<span id="L113" rel="#L113">113</span>
<span id="L114" rel="#L114">114</span>
<span id="L115" rel="#L115">115</span>
<span id="L116" rel="#L116">116</span>
<span id="L117" rel="#L117">117</span>
<span id="L118" rel="#L118">118</span>
<span id="L119" rel="#L119">119</span>
<span id="L120" rel="#L120">120</span>
<span id="L121" rel="#L121">121</span>
<span id="L122" rel="#L122">122</span>
<span id="L123" rel="#L123">123</span>
<span id="L124" rel="#L124">124</span>
<span id="L125" rel="#L125">125</span>
<span id="L126" rel="#L126">126</span>
<span id="L127" rel="#L127">127</span>
<span id="L128" rel="#L128">128</span>
<span id="L129" rel="#L129">129</span>
<span id="L130" rel="#L130">130</span>
<span id="L131" rel="#L131">131</span>
<span id="L132" rel="#L132">132</span>
<span id="L133" rel="#L133">133</span>
<span id="L134" rel="#L134">134</span>
<span id="L135" rel="#L135">135</span>
<span id="L136" rel="#L136">136</span>
<span id="L137" rel="#L137">137</span>
<span id="L138" rel="#L138">138</span>
</pre>
          </td>
          <td width="100%">
                <div class="highlight"><pre><div class='line' id='LC1'><span class="cp">#include &lt;pcl/point_types.h&gt;</span></div><div class='line' id='LC2'><span class="cp">#include &lt;pcl/point_cloud.h&gt;</span></div><div class='line' id='LC3'><span class="cp">#include &lt;pcl/console/parse.h&gt;</span></div><div class='line' id='LC4'><span class="cp">#include &lt;pcl/console/print.h&gt;</span></div><div class='line' id='LC5'><span class="cp">#include &lt;pcl/io/pcd_io.h&gt;</span></div><div class='line' id='LC6'><span class="cp">#include &lt;boost/filesystem.hpp&gt;</span></div><div class='line' id='LC7'><span class="cp">#include &lt;flann/flann.h&gt;</span></div><div class='line' id='LC8'><span class="cp">#include &lt;flann/io/hdf5.h&gt;</span></div><div class='line' id='LC9'><span class="cp">#include &lt;fstream&gt;</span></div><div class='line' id='LC10'><br/></div><div class='line' id='LC11'><span class="k">typedef</span> <span class="n">std</span><span class="o">::</span><span class="n">pair</span><span class="o">&lt;</span><span class="n">std</span><span class="o">::</span><span class="n">string</span><span class="p">,</span> <span class="n">std</span><span class="o">::</span><span class="n">vector</span><span class="o">&lt;</span><span class="kt">float</span><span class="o">&gt;</span> <span class="o">&gt;</span> <span class="n">vfh_model</span><span class="p">;</span></div><div class='line' id='LC12'><br/></div><div class='line' id='LC13'><span class="cm">/** \brief Loads an n-D histogram file as a VFH signature</span></div><div class='line' id='LC14'><span class="cm">  * \param path the input file name</span></div><div class='line' id='LC15'><span class="cm">  * \param vfh the resultant VFH model</span></div><div class='line' id='LC16'><span class="cm">  */</span></div><div class='line' id='LC17'><span class="kt">bool</span></div><div class='line' id='LC18'><span class="n">loadHist</span> <span class="p">(</span><span class="k">const</span> <span class="n">boost</span><span class="o">::</span><span class="n">filesystem</span><span class="o">::</span><span class="n">path</span> <span class="o">&amp;</span><span class="n">path</span><span class="p">,</span> <span class="n">vfh_model</span> <span class="o">&amp;</span><span class="n">vfh</span><span class="p">)</span></div><div class='line' id='LC19'><span class="p">{</span></div><div class='line' id='LC20'>&nbsp;&nbsp;<span class="kt">int</span> <span class="n">vfh_idx</span><span class="p">;</span></div><div class='line' id='LC21'>&nbsp;&nbsp;<span class="c1">// Load the file as a PCD</span></div><div class='line' id='LC22'>&nbsp;&nbsp;<span class="k">try</span></div><div class='line' id='LC23'>&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC24'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">sensor_msgs</span><span class="o">::</span><span class="n">PointCloud2</span> <span class="n">cloud</span><span class="p">;</span></div><div class='line' id='LC25'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">version</span><span class="p">;</span></div><div class='line' id='LC26'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">Eigen</span><span class="o">::</span><span class="n">Vector4f</span> <span class="n">origin</span><span class="p">;</span></div><div class='line' id='LC27'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">Eigen</span><span class="o">::</span><span class="n">Quaternionf</span> <span class="n">orientation</span><span class="p">;</span></div><div class='line' id='LC28'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">pcl</span><span class="o">::</span><span class="n">PCDReader</span> <span class="n">r</span><span class="p">;</span></div><div class='line' id='LC29'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">type</span><span class="p">;</span> </div><div class='line' id='LC30'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">idx</span><span class="p">;</span></div><div class='line' id='LC31'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">r</span><span class="p">.</span><span class="n">readHeader</span> <span class="p">(</span><span class="n">path</span><span class="p">.</span><span class="n">string</span> <span class="p">(),</span> <span class="n">cloud</span><span class="p">,</span> <span class="n">origin</span><span class="p">,</span> <span class="n">orientation</span><span class="p">,</span> <span class="n">version</span><span class="p">,</span> <span class="n">type</span><span class="p">,</span> <span class="n">idx</span><span class="p">);</span></div><div class='line' id='LC32'><br/></div><div class='line' id='LC33'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">vfh_idx</span> <span class="o">=</span> <span class="n">pcl</span><span class="o">::</span><span class="n">getFieldIndex</span> <span class="p">(</span><span class="n">cloud</span><span class="p">,</span> <span class="s">&quot;vfh&quot;</span><span class="p">);</span></div><div class='line' id='LC34'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">vfh_idx</span> <span class="o">==</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC35'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="p">(</span><span class="kc">false</span><span class="p">);</span></div><div class='line' id='LC36'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">((</span><span class="kt">int</span><span class="p">)</span><span class="n">cloud</span><span class="p">.</span><span class="n">width</span> <span class="o">*</span> <span class="n">cloud</span><span class="p">.</span><span class="n">height</span> <span class="o">!=</span> <span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC37'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="p">(</span><span class="kc">false</span><span class="p">);</span></div><div class='line' id='LC38'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC39'>&nbsp;&nbsp;<span class="k">catch</span> <span class="p">(</span><span class="n">pcl</span><span class="o">::</span><span class="n">InvalidConversionException</span> <span class="n">e</span><span class="p">)</span></div><div class='line' id='LC40'>&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC41'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="p">(</span><span class="kc">false</span><span class="p">);</span></div><div class='line' id='LC42'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC43'><br/></div><div class='line' id='LC44'>&nbsp;&nbsp;<span class="c1">// Treat the VFH signature as a single Point Cloud</span></div><div class='line' id='LC45'>&nbsp;&nbsp;<span class="n">pcl</span><span class="o">::</span><span class="n">PointCloud</span> <span class="o">&lt;</span><span class="n">pcl</span><span class="o">::</span><span class="n">VFHSignature308</span><span class="o">&gt;</span> <span class="n">point</span><span class="p">;</span></div><div class='line' id='LC46'>&nbsp;&nbsp;<span class="n">pcl</span><span class="o">::</span><span class="n">io</span><span class="o">::</span><span class="n">loadPCDFile</span> <span class="p">(</span><span class="n">path</span><span class="p">.</span><span class="n">string</span> <span class="p">(),</span> <span class="n">point</span><span class="p">);</span></div><div class='line' id='LC47'>&nbsp;&nbsp;<span class="n">vfh</span><span class="p">.</span><span class="n">second</span><span class="p">.</span><span class="n">resize</span> <span class="p">(</span><span class="mi">308</span><span class="p">);</span></div><div class='line' id='LC48'><br/></div><div class='line' id='LC49'>&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">vector</span> <span class="o">&lt;</span><span class="n">sensor_msgs</span><span class="o">::</span><span class="n">PointField</span><span class="o">&gt;</span> <span class="n">fields</span><span class="p">;</span></div><div class='line' id='LC50'>&nbsp;&nbsp;<span class="n">pcl</span><span class="o">::</span><span class="n">getFieldIndex</span> <span class="p">(</span><span class="n">point</span><span class="p">,</span> <span class="s">&quot;vfh&quot;</span><span class="p">,</span> <span class="n">fields</span><span class="p">);</span></div><div class='line' id='LC51'><br/></div><div class='line' id='LC52'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="n">size_t</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">fields</span><span class="p">[</span><span class="n">vfh_idx</span><span class="p">].</span><span class="n">count</span><span class="p">;</span> <span class="o">++</span><span class="n">i</span><span class="p">)</span></div><div class='line' id='LC53'>&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC54'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">vfh</span><span class="p">.</span><span class="n">second</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="n">point</span><span class="p">.</span><span class="n">points</span><span class="p">[</span><span class="mi">0</span><span class="p">].</span><span class="n">histogram</span><span class="p">[</span><span class="n">i</span><span class="p">];</span></div><div class='line' id='LC55'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC56'>&nbsp;&nbsp;<span class="n">vfh</span><span class="p">.</span><span class="n">first</span> <span class="o">=</span> <span class="n">path</span><span class="p">.</span><span class="n">string</span> <span class="p">();</span></div><div class='line' id='LC57'>&nbsp;&nbsp;<span class="k">return</span> <span class="p">(</span><span class="kc">true</span><span class="p">);</span></div><div class='line' id='LC58'><span class="p">}</span></div><div class='line' id='LC59'><br/></div><div class='line' id='LC60'><span class="cm">/** \brief Load a set of VFH features that will act as the model (training data)</span></div><div class='line' id='LC61'><span class="cm">  * \param argc the number of arguments (pass from main ())</span></div><div class='line' id='LC62'><span class="cm">  * \param argv the actual command line arguments (pass from main ())</span></div><div class='line' id='LC63'><span class="cm">  * \param extension the file extension containing the VFH features</span></div><div class='line' id='LC64'><span class="cm">  * \param models the resultant vector of histogram models</span></div><div class='line' id='LC65'><span class="cm">  */</span></div><div class='line' id='LC66'><span class="kt">void</span></div><div class='line' id='LC67'><span class="n">loadFeatureModels</span> <span class="p">(</span><span class="k">const</span> <span class="n">boost</span><span class="o">::</span><span class="n">filesystem</span><span class="o">::</span><span class="n">path</span> <span class="o">&amp;</span><span class="n">base_dir</span><span class="p">,</span> <span class="k">const</span> <span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="o">&amp;</span><span class="n">extension</span><span class="p">,</span> </div><div class='line' id='LC68'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">vector</span><span class="o">&lt;</span><span class="n">vfh_model</span><span class="o">&gt;</span> <span class="o">&amp;</span><span class="n">models</span><span class="p">)</span></div><div class='line' id='LC69'><span class="p">{</span></div><div class='line' id='LC70'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">boost</span><span class="o">::</span><span class="n">filesystem</span><span class="o">::</span><span class="n">exists</span> <span class="p">(</span><span class="n">base_dir</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="o">!</span><span class="n">boost</span><span class="o">::</span><span class="n">filesystem</span><span class="o">::</span><span class="n">is_directory</span> <span class="p">(</span><span class="n">base_dir</span><span class="p">))</span></div><div class='line' id='LC71'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span><span class="p">;</span></div><div class='line' id='LC72'><br/></div><div class='line' id='LC73'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="n">boost</span><span class="o">::</span><span class="n">filesystem</span><span class="o">::</span><span class="n">directory_iterator</span> <span class="n">it</span> <span class="p">(</span><span class="n">base_dir</span><span class="p">);</span> <span class="n">it</span> <span class="o">!=</span> <span class="n">boost</span><span class="o">::</span><span class="n">filesystem</span><span class="o">::</span><span class="n">directory_iterator</span> <span class="p">();</span> <span class="o">++</span><span class="n">it</span><span class="p">)</span></div><div class='line' id='LC74'>&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC75'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">boost</span><span class="o">::</span><span class="n">filesystem</span><span class="o">::</span><span class="n">is_directory</span> <span class="p">(</span><span class="n">it</span><span class="o">-&gt;</span><span class="n">status</span> <span class="p">()))</span></div><div class='line' id='LC76'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC77'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">stringstream</span> <span class="n">ss</span><span class="p">;</span></div><div class='line' id='LC78'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ss</span> <span class="o">&lt;&lt;</span> <span class="n">it</span><span class="o">-&gt;</span><span class="n">path</span> <span class="p">();</span></div><div class='line' id='LC79'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">pcl</span><span class="o">::</span><span class="n">console</span><span class="o">::</span><span class="n">print_highlight</span> <span class="p">(</span><span class="s">&quot;Loading %s (%lu models loaded so far).</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span> <span class="n">ss</span><span class="p">.</span><span class="n">str</span> <span class="p">().</span><span class="n">c_str</span> <span class="p">(),</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">long</span><span class="p">)</span><span class="n">models</span><span class="p">.</span><span class="n">size</span> <span class="p">());</span></div><div class='line' id='LC80'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">loadFeatureModels</span> <span class="p">(</span><span class="n">it</span><span class="o">-&gt;</span><span class="n">path</span> <span class="p">(),</span> <span class="n">extension</span><span class="p">,</span> <span class="n">models</span><span class="p">);</span></div><div class='line' id='LC81'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC82'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">boost</span><span class="o">::</span><span class="n">filesystem</span><span class="o">::</span><span class="n">is_regular_file</span> <span class="p">(</span><span class="n">it</span><span class="o">-&gt;</span><span class="n">status</span> <span class="p">())</span> <span class="o">&amp;&amp;</span> <span class="n">boost</span><span class="o">::</span><span class="n">filesystem</span><span class="o">::</span><span class="n">extension</span> <span class="p">(</span><span class="n">it</span><span class="o">-&gt;</span><span class="n">path</span> <span class="p">())</span> <span class="o">==</span> <span class="n">extension</span><span class="p">)</span></div><div class='line' id='LC83'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC84'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">vfh_model</span> <span class="n">m</span><span class="p">;</span></div><div class='line' id='LC85'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">loadHist</span> <span class="p">(</span><span class="n">base_dir</span> <span class="o">/</span> <span class="n">it</span><span class="o">-&gt;</span><span class="n">path</span> <span class="p">().</span><span class="n">filename</span> <span class="p">(),</span> <span class="n">m</span><span class="p">))</span></div><div class='line' id='LC86'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">models</span><span class="p">.</span><span class="n">push_back</span> <span class="p">(</span><span class="n">m</span><span class="p">);</span></div><div class='line' id='LC87'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC88'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC89'><span class="p">}</span></div><div class='line' id='LC90'><br/></div><div class='line' id='LC91'><span class="kt">int</span></div><div class='line' id='LC92'><span class="n">main</span> <span class="p">(</span><span class="kt">int</span> <span class="n">argc</span><span class="p">,</span> <span class="kt">char</span><span class="o">**</span> <span class="n">argv</span><span class="p">)</span></div><div class='line' id='LC93'><span class="p">{</span></div><div class='line' id='LC94'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">argc</span> <span class="o">&lt;</span> <span class="mi">2</span><span class="p">)</span></div><div class='line' id='LC95'>&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC96'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">PCL_ERROR</span> <span class="p">(</span><span class="s">&quot;Need at least two parameters! Syntax is: %s [model_directory] [options]</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span> <span class="n">argv</span><span class="p">[</span><span class="mi">0</span><span class="p">]);</span></div><div class='line' id='LC97'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="p">(</span><span class="o">-</span><span class="mi">1</span><span class="p">);</span></div><div class='line' id='LC98'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC99'><br/></div><div class='line' id='LC100'>&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="n">extension</span> <span class="p">(</span><span class="s">&quot;.pcd&quot;</span><span class="p">);</span></div><div class='line' id='LC101'>&nbsp;&nbsp;<span class="n">transform</span> <span class="p">(</span><span class="n">extension</span><span class="p">.</span><span class="n">begin</span> <span class="p">(),</span> <span class="n">extension</span><span class="p">.</span><span class="n">end</span> <span class="p">(),</span> <span class="n">extension</span><span class="p">.</span><span class="n">begin</span> <span class="p">(),</span> <span class="p">(</span><span class="kt">int</span><span class="p">(</span><span class="o">*</span><span class="p">)(</span><span class="kt">int</span><span class="p">))</span><span class="n">tolower</span><span class="p">);</span></div><div class='line' id='LC102'><br/></div><div class='line' id='LC103'>&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="n">kdtree_idx_file_name</span> <span class="o">=</span> <span class="s">&quot;kdtree.idx&quot;</span><span class="p">;</span></div><div class='line' id='LC104'>&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="n">training_data_h5_file_name</span> <span class="o">=</span> <span class="s">&quot;training_data.h5&quot;</span><span class="p">;</span></div><div class='line' id='LC105'>&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="n">training_data_list_file_name</span> <span class="o">=</span> <span class="s">&quot;training_data.list&quot;</span><span class="p">;</span></div><div class='line' id='LC106'><br/></div><div class='line' id='LC107'>&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">vector</span><span class="o">&lt;</span><span class="n">vfh_model</span><span class="o">&gt;</span> <span class="n">models</span><span class="p">;</span></div><div class='line' id='LC108'><br/></div><div class='line' id='LC109'>&nbsp;&nbsp;<span class="c1">// Load the model histograms</span></div><div class='line' id='LC110'>&nbsp;&nbsp;<span class="n">loadFeatureModels</span> <span class="p">(</span><span class="n">argv</span><span class="p">[</span><span class="mi">1</span><span class="p">],</span> <span class="n">extension</span><span class="p">,</span> <span class="n">models</span><span class="p">);</span></div><div class='line' id='LC111'>&nbsp;&nbsp;<span class="n">pcl</span><span class="o">::</span><span class="n">console</span><span class="o">::</span><span class="n">print_highlight</span> <span class="p">(</span><span class="s">&quot;Loaded %d VFH models. Creating training data %s/%s.</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span> </div><div class='line' id='LC112'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">models</span><span class="p">.</span><span class="n">size</span> <span class="p">(),</span> <span class="n">training_data_h5_file_name</span><span class="p">.</span><span class="n">c_str</span> <span class="p">(),</span> <span class="n">training_data_list_file_name</span><span class="p">.</span><span class="n">c_str</span> <span class="p">());</span></div><div class='line' id='LC113'><br/></div><div class='line' id='LC114'>&nbsp;&nbsp;<span class="c1">// Convert data into FLANN format</span></div><div class='line' id='LC115'>&nbsp;&nbsp;<span class="n">flann</span><span class="o">::</span><span class="n">Matrix</span><span class="o">&lt;</span><span class="kt">float</span><span class="o">&gt;</span> <span class="n">data</span> <span class="p">(</span><span class="k">new</span> <span class="kt">float</span><span class="p">[</span><span class="n">models</span><span class="p">.</span><span class="n">size</span> <span class="p">()</span> <span class="o">*</span> <span class="n">models</span><span class="p">[</span><span class="mi">0</span><span class="p">].</span><span class="n">second</span><span class="p">.</span><span class="n">size</span> <span class="p">()],</span> <span class="n">models</span><span class="p">.</span><span class="n">size</span> <span class="p">(),</span> <span class="n">models</span><span class="p">[</span><span class="mi">0</span><span class="p">].</span><span class="n">second</span><span class="p">.</span><span class="n">size</span> <span class="p">());</span></div><div class='line' id='LC116'><br/></div><div class='line' id='LC117'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="n">size_t</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">data</span><span class="p">.</span><span class="n">rows</span><span class="p">;</span> <span class="o">++</span><span class="n">i</span><span class="p">)</span></div><div class='line' id='LC118'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="n">size_t</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="n">data</span><span class="p">.</span><span class="n">cols</span><span class="p">;</span> <span class="o">++</span><span class="n">j</span><span class="p">)</span></div><div class='line' id='LC119'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">data</span><span class="p">[</span><span class="n">i</span><span class="p">][</span><span class="n">j</span><span class="p">]</span> <span class="o">=</span> <span class="n">models</span><span class="p">[</span><span class="n">i</span><span class="p">].</span><span class="n">second</span><span class="p">[</span><span class="n">j</span><span class="p">];</span></div><div class='line' id='LC120'><br/></div><div class='line' id='LC121'>&nbsp;&nbsp;<span class="c1">// Save data to disk (list of models)</span></div><div class='line' id='LC122'>&nbsp;&nbsp;<span class="n">flann</span><span class="o">::</span><span class="n">save_to_file</span> <span class="p">(</span><span class="n">data</span><span class="p">,</span> <span class="n">training_data_h5_file_name</span><span class="p">,</span> <span class="s">&quot;training_data&quot;</span><span class="p">);</span></div><div class='line' id='LC123'>&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">ofstream</span> <span class="n">fs</span><span class="p">;</span></div><div class='line' id='LC124'>&nbsp;&nbsp;<span class="n">fs</span><span class="p">.</span><span class="n">open</span> <span class="p">(</span><span class="n">training_data_list_file_name</span><span class="p">.</span><span class="n">c_str</span> <span class="p">());</span></div><div class='line' id='LC125'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="n">size_t</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">models</span><span class="p">.</span><span class="n">size</span> <span class="p">();</span> <span class="o">++</span><span class="n">i</span><span class="p">)</span></div><div class='line' id='LC126'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">fs</span> <span class="o">&lt;&lt;</span> <span class="n">models</span><span class="p">[</span><span class="n">i</span><span class="p">].</span><span class="n">first</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">;</span></div><div class='line' id='LC127'>&nbsp;&nbsp;<span class="n">fs</span><span class="p">.</span><span class="n">close</span> <span class="p">();</span></div><div class='line' id='LC128'>&nbsp;</div><div class='line' id='LC129'>&nbsp;&nbsp;<span class="c1">// Build the tree index and save it to disk</span></div><div class='line' id='LC130'>&nbsp;&nbsp;<span class="n">pcl</span><span class="o">::</span><span class="n">console</span><span class="o">::</span><span class="n">print_error</span> <span class="p">(</span><span class="s">&quot;Building the kdtree index (%s) for %d elements...</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span> <span class="n">kdtree_idx_file_name</span><span class="p">.</span><span class="n">c_str</span> <span class="p">(),</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span><span class="n">data</span><span class="p">.</span><span class="n">rows</span><span class="p">);</span></div><div class='line' id='LC131'>&nbsp;&nbsp;<span class="n">flann</span><span class="o">::</span><span class="n">Index</span><span class="o">&lt;</span><span class="n">flann</span><span class="o">::</span><span class="n">ChiSquareDistance</span><span class="o">&lt;</span><span class="kt">float</span><span class="o">&gt;</span> <span class="o">&gt;</span> <span class="n">index</span> <span class="p">(</span><span class="n">data</span><span class="p">,</span> <span class="n">flann</span><span class="o">::</span><span class="n">LinearIndexParams</span> <span class="p">());</span></div><div class='line' id='LC132'>&nbsp;&nbsp;<span class="c1">//flann::Index&lt;flann::ChiSquareDistance&lt;float&gt; &gt; index (data, flann::KDTreeIndexParams (4));</span></div><div class='line' id='LC133'>&nbsp;&nbsp;<span class="n">index</span><span class="p">.</span><span class="n">buildIndex</span> <span class="p">();</span></div><div class='line' id='LC134'>&nbsp;&nbsp;<span class="n">index</span><span class="p">.</span><span class="n">save</span> <span class="p">(</span><span class="n">kdtree_idx_file_name</span><span class="p">);</span></div><div class='line' id='LC135'>&nbsp;&nbsp;<span class="k">delete</span><span class="p">[]</span> <span class="n">data</span><span class="p">.</span><span class="n">ptr</span> <span class="p">();</span></div><div class='line' id='LC136'><br/></div><div class='line' id='LC137'>&nbsp;&nbsp;<span class="k">return</span> <span class="p">(</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC138'><span class="p">}</span></div></pre></div>
          </td>
        </tr>
      </table>
  </div>

          </div>
        </div>
      </div>
    </div>

  </div>

<div class="frame frame-loading large-loading-area" style="display:none;" data-tree-list-url="/jvgomez/irml/tree-list/b331eeb6b32d46dfb53fd6c2c2f55d5e85c6f436" data-blob-url-prefix="/jvgomez/irml/blob/b331eeb6b32d46dfb53fd6c2c2f55d5e85c6f436">
  <img src="https://a248.e.akamai.net/assets.github.com/images/spinners/octocat-spinner-64.gif?1329872005" height="64" width="64">
</div>

        </div>
      </div>
      <div class="context-overlay"></div>
    </div>

      <div id="footer-push"></div><!-- hack for sticky footer -->
    </div><!-- end of wrapper - hack for sticky footer -->

      <!-- footer -->
      <div id="footer" >
        
  <div class="upper_footer">
     <div class="container clearfix">

       <!--[if IE]><h4 id="blacktocat_ie">GitHub Links</h4><![endif]-->
       <![if !IE]><h4 id="blacktocat">GitHub Links</h4><![endif]>

       <ul class="footer_nav">
         <h4>GitHub</h4>
         <li><a href="https://github.com/about">About</a></li>
         <li><a href="https://github.com/blog">Blog</a></li>
         <li><a href="https://github.com/features">Features</a></li>
         <li><a href="https://github.com/contact">Contact &amp; Support</a></li>
         <li><a href="https://github.com/training">Training</a></li>
         <li><a href="http://enterprise.github.com/">GitHub Enterprise</a></li>
         <li><a href="http://status.github.com/">Site Status</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Clients</h4>
         <li><a href="http://mac.github.com/">GitHub for Mac</a></li>
         <li><a href="http://windows.github.com/">GitHub for Windows</a></li>
         <li><a href="http://eclipse.github.com/">GitHub for Eclipse</a></li>
         <li><a href="http://mobile.github.com/">GitHub Mobile Apps</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Tools</h4>
         <li><a href="http://get.gaug.es/">Gauges: Web analytics</a></li>
         <li><a href="http://speakerdeck.com">Speaker Deck: Presentations</a></li>
         <li><a href="https://gist.github.com">Gist: Code snippets</a></li>

         <h4 class="second">Extras</h4>
         <li><a href="http://jobs.github.com/">Job Board</a></li>
         <li><a href="http://shop.github.com/">GitHub Shop</a></li>
         <li><a href="http://octodex.github.com/">The Octodex</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Documentation</h4>
         <li><a href="http://help.github.com/">GitHub Help</a></li>
         <li><a href="http://developer.github.com/">Developer API</a></li>
         <li><a href="http://github.github.com/github-flavored-markdown/">GitHub Flavored Markdown</a></li>
         <li><a href="http://pages.github.com/">GitHub Pages</a></li>
       </ul>

     </div><!-- /.site -->
  </div><!-- /.upper_footer -->

<div class="lower_footer">
  <div class="container clearfix">
    <!--[if IE]><div id="legal_ie"><![endif]-->
    <![if !IE]><div id="legal"><![endif]>
      <ul>
          <li><a href="https://github.com/site/terms">Terms of Service</a></li>
          <li><a href="https://github.com/site/privacy">Privacy</a></li>
          <li><a href="https://github.com/security">Security</a></li>
      </ul>

      <p>&copy; 2012 <span title="0.23689s from fe10.rs.github.com">GitHub</span> Inc. All rights reserved.</p>
    </div><!-- /#legal or /#legal_ie-->

      <div class="sponsor">
        <a href="http://www.rackspace.com" class="logo">
          <img alt="Dedicated Server" height="36" src="https://a248.e.akamai.net/assets.github.com/images/modules/footer/rackspaces_logo.png?1329521039" width="38" />
        </a>
        Powered by the <a href="http://www.rackspace.com ">Dedicated
        Servers</a> and<br/> <a href="http://www.rackspacecloud.com">Cloud
        Computing</a> of Rackspace Hosting<span>&reg;</span>
      </div>
  </div><!-- /.site -->
</div><!-- /.lower_footer -->

      </div><!-- /#footer -->

    

<div id="keyboard_shortcuts_pane" class="instapaper_ignore readability-extra" style="display:none">
  <h2>Keyboard Shortcuts <small><a href="#" class="js-see-all-keyboard-shortcuts">(see all)</a></small></h2>

  <div class="columns threecols">
    <div class="column first">
      <h3>Site wide shortcuts</h3>
      <dl class="keyboard-mappings">
        <dt>s</dt>
        <dd>Focus site search</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>?</dt>
        <dd>Bring up this help dialog</dd>
      </dl>
    </div><!-- /.column.first -->

    <div class="column middle" style='display:none'>
      <h3>Commit list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selection down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selection up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>c <em>or</em> o <em>or</em> enter</dt>
        <dd>Open commit</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>y</dt>
        <dd>Expand URL to its canonical form</dd>
      </dl>
    </div><!-- /.column.first -->

    <div class="column last" style='display:none'>
      <h3>Pull request list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selection down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selection up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>o <em>or</em> enter</dt>
        <dd>Open issue</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt><span class="platform-mac">⌘</span><span class="platform-other">ctrl</span> <em>+</em> enter</dt>
        <dd>Submit comment</dd>
      </dl>
    </div><!-- /.columns.last -->

  </div><!-- /.columns.equacols -->

  <div style='display:none'>
    <div class="rule"></div>

    <h3>Issues</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>x</dt>
          <dd>Toggle selection</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open issue</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="platform-mac">⌘</span><span class="platform-other">ctrl</span> <em>+</em> enter</dt>
          <dd>Submit comment</dd>
        </dl>
      </div><!-- /.column.first -->
      <div class="column last">
        <dl class="keyboard-mappings">
          <dt>c</dt>
          <dd>Create issue</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>l</dt>
          <dd>Create label</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>i</dt>
          <dd>Back to inbox</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>u</dt>
          <dd>Back to issues</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>/</dt>
          <dd>Focus issues search</dd>
        </dl>
      </div>
    </div>
  </div>

  <div style='display:none'>
    <div class="rule"></div>

    <h3>Issues Dashboard</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open issue</dd>
        </dl>
      </div><!-- /.column.first -->
    </div>
  </div>

  <div style='display:none'>
    <div class="rule"></div>

    <h3>Network Graph</h3>
    <div class="columns equacols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt><span class="badmono">←</span> <em>or</em> h</dt>
          <dd>Scroll left</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">→</span> <em>or</em> l</dt>
          <dd>Scroll right</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">↑</span> <em>or</em> k</dt>
          <dd>Scroll up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">↓</span> <em>or</em> j</dt>
          <dd>Scroll down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>t</dt>
          <dd>Toggle visibility of head labels</dd>
        </dl>
      </div><!-- /.column.first -->
      <div class="column last">
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">←</span> <em>or</em> shift h</dt>
          <dd>Scroll all the way left</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">→</span> <em>or</em> shift l</dt>
          <dd>Scroll all the way right</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">↑</span> <em>or</em> shift k</dt>
          <dd>Scroll all the way up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">↓</span> <em>or</em> shift j</dt>
          <dd>Scroll all the way down</dd>
        </dl>
      </div><!-- /.column.last -->
    </div>
  </div>

  <div >
    <div class="rule"></div>
    <div class="columns threecols">
      <div class="column first" >
        <h3>Source Code Browsing</h3>
        <dl class="keyboard-mappings">
          <dt>t</dt>
          <dd>Activates the file finder</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>l</dt>
          <dd>Jump to line</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>w</dt>
          <dd>Switch branch/tag</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>y</dt>
          <dd>Expand URL to its canonical form</dd>
        </dl>
      </div>
    </div>
  </div>

  <div style='display:none'>
    <div class="rule"></div>
    <div class="columns threecols">
      <div class="column first">
        <h3>Browsing Commits</h3>
        <dl class="keyboard-mappings">
          <dt><span class="platform-mac">⌘</span><span class="platform-other">ctrl</span> <em>+</em> enter</dt>
          <dd>Submit comment</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>escape</dt>
          <dd>Close form</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>p</dt>
          <dd>Parent commit</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o</dt>
          <dd>Other parent commit</dd>
        </dl>
      </div>
    </div>
  </div>
</div>

    <div id="markdown-help" class="instapaper_ignore readability-extra">
  <h2>Markdown Cheat Sheet</h2>

  <div class="cheatsheet-content">

  <div class="mod">
    <div class="col">
      <h3>Format Text</h3>
      <p>Headers</p>
      <pre>
# This is an &lt;h1&gt; tag
## This is an &lt;h2&gt; tag
###### This is an &lt;h6&gt; tag</pre>
     <p>Text styles</p>
     <pre>
*This text will be italic*
_This will also be italic_
**This text will be bold**
__This will also be bold__

*You **can** combine them*
</pre>
    </div>
    <div class="col">
      <h3>Lists</h3>
      <p>Unordered</p>
      <pre>
* Item 1
* Item 2
  * Item 2a
  * Item 2b</pre>
     <p>Ordered</p>
     <pre>
1. Item 1
2. Item 2
3. Item 3
   * Item 3a
   * Item 3b</pre>
    </div>
    <div class="col">
      <h3>Miscellaneous</h3>
      <p>Images</p>
      <pre>
![GitHub Logo](/images/logo.png)
Format: ![Alt Text](url)
</pre>
     <p>Links</p>
     <pre>
http://github.com - automatic!
[GitHub](http://github.com)</pre>
<p>Blockquotes</p>
     <pre>
As Kanye West said:

> We're living the future so
> the present is our past.
</pre>
    </div>
  </div>
  <div class="rule"></div>

  <h3>Code Examples in Markdown</h3>
  <div class="col">
      <p>Syntax highlighting with <a href="http://github.github.com/github-flavored-markdown/" title="GitHub Flavored Markdown" target="_blank">GFM</a></p>
      <pre>
```javascript
function fancyAlert(arg) {
  if(arg) {
    $.facebox({div:'#foo'})
  }
}
```</pre>
    </div>
    <div class="col">
      <p>Or, indent your code 4 spaces</p>
      <pre>
Here is a Python code example
without syntax highlighting:

    def foo:
      if not bar:
        return true</pre>
    </div>
    <div class="col">
      <p>Inline code for comments</p>
      <pre>
I think you should use an
`&lt;addr&gt;` element here instead.</pre>
    </div>
  </div>

  </div>
</div>


    <div id="ajax-error-message">
      <span class="mini-icon mini-icon-exclamation"></span>
      Something went wrong with that request. Please try again.
      <a href="#" class="ajax-error-dismiss">Dismiss</a>
    </div>

    <div id="logo-popup">
      <h2>Looking for the GitHub logo?</h2>
      <ul>
        <li>
          <h4>GitHub Logo</h4>
          <a href="http://github-media-downloads.s3.amazonaws.com/GitHub_Logos.zip"><img alt="Github_logo" src="https://a248.e.akamai.net/assets.github.com/images/modules/about_page/github_logo.png?1315937507" /></a>
          <a href="http://github-media-downloads.s3.amazonaws.com/GitHub_Logos.zip" class="minibutton btn-download download">Download</a>
        </li>
        <li>
          <h4>The Octocat</h4>
          <a href="http://github-media-downloads.s3.amazonaws.com/Octocats.zip"><img alt="Octocat" src="https://a248.e.akamai.net/assets.github.com/images/modules/about_page/octocat.png?1315937507" /></a>
          <a href="http://github-media-downloads.s3.amazonaws.com/Octocats.zip" class="minibutton btn-download download">Download</a>
        </li>
      </ul>
    </div>

    
    <span id='server_response_time' data-time='0.24364' data-host='fe10'></span>
  </body>
</html>

