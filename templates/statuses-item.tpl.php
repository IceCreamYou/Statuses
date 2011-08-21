<?php

/**
 * @file
 *   Displays individual status updates.
 *
 * See http://drupal.org/node/226776 for a list of default variables.
 *
 * Other variables available:
 * - $sid: The status message ID
 * - $meta: Information about the context of the status message, like "In response to [recipient]"
 * - $self: Whether the status is an update to the sender's own status
 * - $page: Whether the status is being displayed on its own page
 * - $type: The recipient type
 * - $recipient: The recipient object
 * - $recipient_name: The (safe) recipient name
 * - $recipient_link: A link to the recipient
 * - $recipient_picture: The recipient's picture, if applicable
 * - $sender: The sender object
 * - $sender_name: The (safe) sender name
 * - $sender_link: A themed link to the sender
 * - $sender_picture: The sender's picture
 * - $created: The themed message created time
 * - $message: The themed status message
 * - $links: Status links (edit/delete/respond/share)
 * - $status_url: The URL of the status message
 * - $status: The status object
 * - $context: The context array
 *
 * If the Statuses Comments module is enabled, these variables
 * are also available:
 * - $comments: Comments on the relevant status plus the form to leave a comment
 *
 * If the Statuses Private Statuses module is enabled, these
 * variables are also available:
 * - $private: Whether the status update is private or not
 * - $private_text: The translated version of either "Private" or "Public"
 *
 * If the (third-party) Facebook-style Micropublisher module is enabled, these
 * variables are also available:
 * - $attachment: The themed attachment to the status update
 *
 * Other modules may add additional variables.
 */
?>
<div id="statuses-item-<?php echo $sid; ?>" class="statuses-item facebook-status-type-<?php echo $type; ?><?php if ($self): ?> facebook-status-self-update<?php endif; ?><?php if ($page): ?> facebook-status-page<?php endif; ?><?php if ($private): ?> facebook-status-private<?php endif; ?>">
  <?php if (!empty($sender_picture)): ?>
    <div class="statuses-sender-picture"><?php echo $sender_picture; ?></div>
  <?php endif; ?>
  <span class="statuses-sender"><?php echo $sender_link; ?></span>
  <?php if ($type == 'user' && !$self): ?>
    &raquo; <span class="statuses-recipient"><?php echo $recipient_link; ?></span>
  <?php endif; ?>
  <?php if (!empty($private)): ?>
    <span class="statuses-private-text"><?php echo $private_text; ?></span>
  <?php endif; ?>
  <span class="statuses-content"><?php echo $message; ?></span>
  <?php if (!empty($attachment)): ?>
    <div class="fbsmp clearfix"><?php echo $attachment; ?></div>
  <?php endif; ?>
  <div class="statuses-details">
    <span class="statuses-time">
      <?php if (!$page): ?>
        <a href="<?php echo $status_url; ?>">
      <?php endif; ?>
      <?php echo $created; ?>
      <?php if (!$page): ?>
        </a>
      <?php endif; ?>
    </span>
    <?php if (!empty($meta)): ?>
      <span class="statuses-meta"><?php echo $meta; ?></span>
    <?php endif; ?>
    <?php if (!empty($links)): ?>
      <span class="statuses-links"><?php echo $links; ?></span>
    <?php endif; ?>
  </div>
  <?php if (!empty($comments)): ?>
    <div class="statuses-comments"><?php echo $comments; ?></div>
  <?php endif; ?>
</div>
